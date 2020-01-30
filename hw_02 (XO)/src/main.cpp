#include "StdioBoardView.hpp"
#include "NcursesBoardView.hpp"

#include <string.h>

int main(int argc, char* argv[]) {

	bool silent = (argc >= 2 && strcmp(argv[1], "silent") == 0);
	bool ncurses = (argc >= 2 && strcmp(argv[1], "ncurses") == 0);

	Board board;
	if (ncurses) {
		NcursesBoardView nbv(board);
		nbv.doGameCycle();
	} else {
		StdioBoardView sbv(board, silent);
		sbv.doGameCycle();
	}

    return 0;
}
