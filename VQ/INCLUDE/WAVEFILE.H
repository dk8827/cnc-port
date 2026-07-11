/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef WAVEFILE_H
#define WAVEFILE_H

/* WAVHeader: WAVE file header.
 *
 * RIFF - 4 byte identifier (always "RIFF").
 * Size - Size in bytes of entire file.
 * WAVE - 4 byte identifier (always "WAVE").
 */
typedef struct _WAVHeader {
	long RIFF;
	long Size;
	long WAVE;
} WAVHeader;

/* WAVFormat: This structure describes the format of the audio data contained
 *            in the WAV file.
 *
 * FormatTag      - 
 * Channels       - Number of channels (1 = mono, 2 = stereo).
 * SamplesPerSec  - Sampling rate.
 * AvgBytesPerSec - Bytes in 1 second of audio (Rate * SampleSize * Channels)
 * BlockAlign     - padding.
 * BitsPerSample  - Number of bits per sample (8, 16).
 */
typedef struct _WAVFormat {
	short FormatTag;
	short Channels;
	long  SamplesPerSec;
 	long  AvgBytesPerSec;
	short BlockAlign;
	short BitsPerSample;
} WAVFormat;

#endif /* WAVEFILE_H */

