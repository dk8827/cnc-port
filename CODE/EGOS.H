/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

class EgoClass {

	public:

		EgoClass (int x, int y, char *text, TextPrintType flags);
		~EgoClass ();

		bool Scroll (int distance);
		void Render (void);
		void Wipe (GraphicBufferClass *background);


		char				*Text;
		int				XPos;
		int				YPos;
		TextPrintType 	Flags;
};


