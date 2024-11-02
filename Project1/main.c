#include "main.h"

int main() {
	init();
	while (1) {
		titleDraw();
		int menuCode = menuDraw();
		if (menuCode == 0) {
			// 게임시작  
		}
		else if (menuCode == 1) {
			infoDraw(); // 게임정보  
		}
		else if (menuCode == 2) {
			return 0; // 종료
		}
		system("cls");
	}
	return 0;
}
