/*******************************************************************************
* Copyright © 2017 TRINAMIC Motion Control GmbH & Co. KG
* (now owned by Analog Devices Inc.),
*
* Copyright © 2023 Analog Devices Inc. All Rights Reserved.
* This software is proprietary to Analog Devices, Inc. and its licensors.
*******************************************************************************/


#include "TMC2225.h"

TMC2225TypeDef TMC2225;

#ifdef TMC_API_EXTERNAL_CRC_TABLE
extern const uint8_t tmcCRCTable_Poly7Reflected[256];
#else
const uint8_t tmcCRCTable_Poly7Reflected[256] = {
			0x00, 0x91, 0xE3, 0x72, 0x07, 0x96, 0xE4, 0x75, 0x0E, 0x9F, 0xED, 0x7C, 0x09, 0x98, 0xEA, 0x7B,
			0x1C, 0x8D, 0xFF, 0x6E, 0x1B, 0x8A, 0xF8, 0x69, 0x12, 0x83, 0xF1, 0x60, 0x15, 0x84, 0xF6, 0x67,
			0x38, 0xA9, 0xDB, 0x4A, 0x3F, 0xAE, 0xDC, 0x4D, 0x36, 0xA7, 0xD5, 0x44, 0x31, 0xA0, 0xD2, 0x43,
			0x24, 0xB5, 0xC7, 0x56, 0x23, 0xB2, 0xC0, 0x51, 0x2A, 0xBB, 0xC9, 0x58, 0x2D, 0xBC, 0xCE, 0x5F,
			0x70, 0xE1, 0x93, 0x02, 0x77, 0xE6, 0x94, 0x05, 0x7E, 0xEF, 0x9D, 0x0C, 0x79, 0xE8, 0x9A, 0x0B,
			0x6C, 0xFD, 0x8F, 0x1E, 0x6B, 0xFA, 0x88, 0x19, 0x62, 0xF3, 0x81, 0x10, 0x65, 0xF4, 0x86, 0x17,
			0x48, 0xD9, 0xAB, 0x3A, 0x4F, 0xDE, 0xAC, 0x3D, 0x46, 0xD7, 0xA5, 0x34, 0x41, 0xD0, 0xA2, 0x33,
			0x54, 0xC5, 0xB7, 0x26, 0x53, 0xC2, 0xB0, 0x21, 0x5A, 0xCB, 0xB9, 0x28, 0x5D, 0xCC, 0xBE, 0x2F,
			0xE0, 0x71, 0x03, 0x92, 0xE7, 0x76, 0x04, 0x95, 0xEE, 0x7F, 0x0D, 0x9C, 0xE9, 0x78, 0x0A, 0x9B,
			0xFC, 0x6D, 0x1F, 0x8E, 0xFB, 0x6A, 0x18, 0x89, 0xF2, 0x63, 0x11, 0x80, 0xF5, 0x64, 0x16, 0x87,
			0xD8, 0x49, 0x3B, 0xAA, 0xDF, 0x4E, 0x3C, 0xAD, 0xD6, 0x47, 0x35, 0xA4, 0xD1, 0x40, 0x32, 0xA3,
			0xC4, 0x55, 0x27, 0xB6, 0xC3, 0x52, 0x20, 0xB1, 0xCA, 0x5B, 0x29, 0xB8, 0xCD, 0x5C, 0x2E, 0xBF,
			0x90, 0x01, 0x73, 0xE2, 0x97, 0x06, 0x74, 0xE5, 0x9E, 0x0F, 0x7D, 0xEC, 0x99, 0x08, 0x7A, 0xEB,
			0x8C, 0x1D, 0x6F, 0xFE, 0x8B, 0x1A, 0x68, 0xF9, 0x82, 0x13, 0x61, 0xF0, 0x85, 0x14, 0x66, 0xF7,
			0xA8, 0x39, 0x4B, 0xDA, 0xAF, 0x3E, 0x4C, 0xDD, 0xA6, 0x37, 0x45, 0xD4, 0xA1, 0x30, 0x42, 0xD3,
			0xB4, 0x25, 0x57, 0xC6, 0xB3, 0x22, 0x50, 0xC1, 0xBA, 0x2B, 0x59, 0xC8, 0xBD, 0x2C, 0x5E, 0xCF,
};
#endif
/**************************************************************** Cache Implementation *************************************************************************/
#if TMC2225_CACHE == 0
static inline bool tmc2225_cache(uint16_t icID, TMC2225CacheOp operation, uint8_t address, uint32_t *value)

{
    UNUSED(icID);
    UNUSED(address);
    UNUSED(operation);
    return false;
}
#else
#if TMC2225_ENABLE_TMC_CACHE == 1
uint8_t tmc2225_dirtyBits[TMC2225_IC_CACHE_COUNT][TMC2225_REGISTER_COUNT/8]= {0};
int32_t tmc2225_shadowRegister[TMC2225_IC_CACHE_COUNT][TMC2225_REGISTER_COUNT];

void tmc2225_setDirtyBit(uint16_t icID, uint8_t index, bool value)
{
    if(index >= TMC2225_REGISTER_COUNT)
        return;

    uint8_t *tmp = &tmc2225_dirtyBits[icID][index / 8];
    uint8_t shift = (index % 8);
    uint8_t mask = 1 << shift;
    *tmp = (((*tmp) & (~(mask))) | (((value) << (shift)) & (mask)));
}

bool tmc2225_getDirtyBit(uint16_t icID, uint8_t index)
{
   if(index >= TMC2225_REGISTER_COUNT)
       return false;

   uint8_t *tmp = &tmc2225_dirtyBits[icID][index / 8];
   uint8_t shift = (index % 8);
   return ((*tmp) >> shift) & 1;
 }

/*
 * This function is used to cache the value written to the Write-Only registers in the form of shadow array.
 * The shadow copy is then used to read these kinds of registers.
 */
bool tmc2225_cache(uint16_t icID, TMC2225CacheOp operation, uint8_t address, uint32_t *value)
{
    if (operation == TMC2225_CACHE_READ)
    {
        // Check if the value should come from cache

        // Only supported chips have a cache
        if (icID >= TMC2225_IC_CACHE_COUNT)
            return false;

        // Only non-readable registers care about caching
        // Note: This could also be used to cache i.e. RW config registers to reduce bus accesses
        if (TMC2225_IS_READABLE(tmc2225_registerAccess[address]))
            return false;

        // Grab the value from the cache
        *value = tmc2225_shadowRegister[icID][address];
        return true;
    }
    else if (operation == TMC2225_CACHE_WRITE || operation == TMC2225_CACHE_FILL_DEFAULT)
    {
        // Fill the cache

        // only supported chips have a cache
        if (icID >= TMC2225_IC_CACHE_COUNT)
            return false;

        // Write to the shadow register and mark the register dirty
        tmc2225_shadowRegister[icID][address] = *value;

        if (operation == TMC2225_CACHE_WRITE)
        {
            tmc2225_setDirtyBit(icID, address, true);
        }

        return true;
    }
    return false;
}

#else
// User must implement their own cache
extern bool tmc2225_cache(uint16_t icID, TMC2225CacheOp operation, uint8_t address, uint32_t *value);
#endif
#endif

/************************************************************** Register read / write Implementation ******************************************************************/
static int32_t readRegisterUART(uint16_t icID, uint8_t registerAddress);
static void writeRegisterUART(uint16_t icID, uint8_t registerAddress, int32_t value);
static uint8_t CRC8(uint8_t *data, uint32_t bytes);


int32_t tmc2225_readRegister(uint16_t icID, uint8_t address)
{
    uint32_t value;

    // Read from cache for registers with write-only access
    if (tmc2225_cache(icID, TMC2225_CACHE_READ, address, &value))
        return value;

    return readRegisterUART(icID, address);

	// ToDo: Error handling
}

void tmc2225_writeRegister(uint16_t icID, uint8_t address, int32_t value)
{
    writeRegisterUART(icID, address, value);
}

int32_t readRegisterUART(uint16_t icID, uint8_t registerAddress)
{
    uint8_t data[8] = {0};

    registerAddress = registerAddress & TMC2225_ADDRESS_MASK;

    data[0] = 0x05;
    data[1] = tmc2225_getNodeAddress(icID);
    data[2] = registerAddress;
    data[3] = CRC8(data, 3);

    if (!tmc2225_readWriteUART(icID, &data[0], 4, 8))
        return 0;

    // Byte 0: Sync nibble correct?
    if (data[0] != 0x05)
        return 0;
/***************** The following code is TMC-EvalSystem specific and needs to be commented out when working with other MCUs e.g Arduino*****************************/

    // Byte 1: Master address correct?
    if (data[1] != 0xFF)
        return 0;

    // Byte 2: Address correct?
    if (data[2] != registerAddress)
        return 0;
void tmc2225_init(TMC2225TypeDef *tmc2225, uint8_t channel, ConfigurationTypeDef *tmc2225_config, const int32_t *registerResetState)
{
	tmc2225->config               = tmc2225_config;
	tmc2225->config->callback     = NULL;
	tmc2225->config->channel      = channel;
	tmc2225->config->configIndex  = 0;
	tmc2225->config->state        = CONFIG_READY;

	for(size_t i = 0; i < TMC2225_REGISTER_COUNT; i++)
	{
		tmc2225->registerAccess[i]      = tmc2225_defaultRegisterAccess[i];
		tmc2225->registerResetState[i]  = registerResetState[i];
	}
}

    // Byte 7: CRC correct?
    if (data[7] != CRC8(data, 7))
        return 0;
static void writeConfiguration(TMC2225TypeDef *tmc2225)
{
	uint8_t *ptr = &tmc2225->config->configIndex;
	const int32_t *settings;

	if(tmc2225->config->state == CONFIG_RESTORE)
	{
		settings = tmc2225->config->shadowRegister;
		// Find the next restorable register
		while((*ptr < TMC2225_REGISTER_COUNT) && !TMC_IS_RESTORABLE(tmc2225->registerAccess[*ptr]))
		{
			(*ptr)++;
		}
	}
	else
	{
		settings = tmc2225->registerResetState;
		// Find the next resettable register
		while((*ptr < TMC2225_REGISTER_COUNT) && !TMC_IS_RESETTABLE(tmc2225->registerAccess[*ptr]))
		{
			(*ptr)++;
		}
	}

	if(*ptr < TMC2225_REGISTER_COUNT)
	{
		tmc2225_writeRegister(tmc2225, *ptr, settings[*ptr]);
		(*ptr)++;
	}
	else // Finished configuration
	{
		if(tmc2225->config->callback)
		{
			((tmc2225_callback)tmc2225->config->callback)(tmc2225, tmc2225->config->state);
		}

		tmc2225->config->state = CONFIG_READY;
	}
}

    return ((uint32_t) data[3] << 24) | ((uint32_t) data[4] << 16) | ((uint32_t) data[5] << 8) | data[6];
void tmc2225_periodicJob(TMC2225TypeDef *tmc2225, uint32_t tick)
{
	UNUSED(tick);

	if(tmc2225->config->state != CONFIG_READY)
	{
		writeConfiguration(tmc2225);
		return;
	}
}

void writeRegisterUART(uint16_t icID, uint8_t registerAddress, int32_t value)
void tmc2225_setRegisterResetState(TMC2225TypeDef *tmc2225, const int32_t *resetState)
{
	for(size_t i = 0; i < TMC2225_REGISTER_COUNT; i++)
	{
		tmc2225->registerResetState[i] = resetState[i];
	}
}

void tmc2225_setCallback(TMC2225TypeDef *tmc2225, tmc2225_callback callback)
{
	tmc2225->config->callback = (tmc_callback_config) callback;
}

uint8_t tmc2225_reset(TMC2225TypeDef *tmc2225)
{
    uint8_t data[8];
	if(tmc2225->config->state != CONFIG_READY)
		return false;

    data[0] = 0x05;
    data[1] = tmc2225_getNodeAddress(icID);
    data[2] = registerAddress | TMC2225_WRITE_BIT;
    data[3] = (value >> 24) & 0xFF;
    data[4] = (value >> 16) & 0xFF;
    data[5] = (value >> 8) & 0xFF;
    data[6] = (value) & 0xFF;
    data[7] = CRC8(data, 7);
	// Reset the dirty bits and wipe the shadow registers
	for(size_t i = 0; i < TMC2225_REGISTER_COUNT; i++)
	{
		tmc2225->registerAccess[i] &= ~TMC_ACCESS_DIRTY;
		tmc2225->config->shadowRegister[i] = 0;
	}

    tmc2225_readWriteUART(icID, &data[0], 8, 0);
	tmc2225->config->state        = CONFIG_RESET;
	tmc2225->config->configIndex  = 0;

    //Cache the registers with write-only access
    tmc2225_cache(icID, TMC2225_CACHE_WRITE, registerAddress, &value);
	return true;
}

static uint8_t CRC8(uint8_t *data, uint32_t bytes)
uint8_t tmc2225_restore(TMC2225TypeDef *tmc2225)
{
    uint8_t result = 0;
    uint8_t *table;
	if(tmc2225->config->state != CONFIG_READY)
		return false;

	tmc2225->config->state        = CONFIG_RESTORE;
	tmc2225->config->configIndex  = 0;

    while (bytes--) result = tmcCRCTable_Poly7Reflected[result ^ *data++];
	return true;
}

    // Flip the result around
    // swap odd and even bits
    result = ((result >> 1) & 0x55) | ((result & 0x55) << 1);
    // swap consecutive pairs
    result = ((result >> 2) & 0x33) | ((result & 0x33) << 2);
    // swap nibbles ...
    result = ((result >> 4) & 0x0F) | ((result & 0x0F) << 4);
void tmc2225_set_slave(TMC2225TypeDef *tmc2225, uint8_t slave)
{
	tmc2225->slave_address = slave;
}

    return result;
uint8_t tmc2225_get_slave(TMC2225TypeDef *tmc2225)
{
	return tmc2225->slave_address;
}
