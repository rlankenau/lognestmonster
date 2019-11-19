// lognestmonster Copyright (c) 2019 Joshua 'joshuas3' Stockin
// main.c
// C file for testing the lognestmonster library header

// <https://github.com/JoshuaS3/lognestmonster/>.


// This file is part of lognestmonster.

// lognestmonster is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// lognestmonster is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with lognestmonster. If not, see <https://www.gnu.org/licenses/>.

#include <stdio.h>
#include "lognestmonster.h"

int main(void) {
	printf("lognestmonster C test main()\n");
	printf("enums:\n");
	printf("\tInfo: %d\n\tDebug: %d\n\tVerbose: %d\n\tVeryVerbose: %d\n\tWarning: %d\n\tError: %d\n", lnmInfo, lnmDebug, lnmVerbose, lnmVeryVerbose, lnmWarning, lnmError);

	lnmItem statement = lnmStatement(lnmDebug, "tag", "message");
	lnmItem event = lnmEvent();
	lnmItem event2 = lnmEvent();
	lnmEventPush(event, statement);

	lnmEventPush(event2, statement);
	lnmEventPush(event, event2);
	lnmEventPush(event2, statement);

	lnm_debug_parse(event, 0);

	return 0;
}