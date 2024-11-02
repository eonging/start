#include "game.h" 

void infoDraw() {
    system("cls");
    printf("\n\n");
    printf("                  [ 게임규칙 ]\n\n");
    printf("                              \n\n"); //괄호 안 게임규칙 내용 추가
    printf("      스페이스바를 누르면 초기화면으로 이동합니다.");

    while (1) {
        if (keyControl() == SUBMIT) {
            break;
        }
    }
}
int keyControl() {
    char temp = getch();

    if (temp == 'w' || temp == 'W') {
        return UP;
    }
    else if (temp == 's' || temp == 'S') {
        return DOWN;

    }
    else if (temp == ' ') {
        return SUBMIT;
    }
}
void titleDraw() {
    printf("\n\n\n\n");
    printf("             =$            $.           =$                               $:     \n");
    printf("      @@@;   @@  !==@@==!  @.  ===@$==  @@            *@@@,    -$===$#,  @!     \n");
    printf("     !@.!@   @@  $@@@@@@$*:@.  @@@#@@@  @@.,        *@@$~@@@,  ~@@@@@@=  @!     \n");
    printf("     *@ ~@   @@   ;@  @- @@@.   @; ~@   @@@!      *@@;    -@@#       @:  @!     \n");
    printf("     .@@@$   @@   ~@:;@    @.   @@ #@   @@        @*   $@   :@       @;  @!     \n");
    printf("       ;~    @@    =@@$    @.   .@@@-   @@        *;;;;#@;;;;!~      @=  @!     \n");
    printf("   :@@@@@@@@@@@                         @@        @@@@@@@@@@@@* ;;;:~~:;;;      \n");
    printf("    !!!@@!!!!@@   @@@@@@@@@@.  :*       !*        -$            @@@@@@@@@@!     \n");
    printf("       @@    @@   @$*******@.  #@                 ~@            @@@@@@@@@@!     \n");
    printf("       @@    @@   @;      ,@.  #@,.   ..,-        ~@-.    .,--  @@,....,~*      \n");
    printf("       @@    @@   @@@@@@@@@@.  @@@@@@@@@@@,       =@@@@@@@@@@@  @@@@@@@@@@@     \n");

}
int menuDraw() {
    int x = 40;
    int y = 26;

    gotoxy(x - 2, 26);
    printf("> 게임시작 ");
    gotoxy(40, 27);
    printf("게임규칙 ");
    gotoxy(40, 28);
    printf("  종료 ");
    while (1) {
        int n = keyControl();
        switch (n) {
        case UP: {
            if (y > 26) {
                gotoxy(x - 2, y);
                printf(" ");
                gotoxy(x - 2, --y);
                printf(">");
            }
            break;
        }
        case DOWN: {
            if (y < 28) {
                gotoxy(x - 2, y);
                printf(" ");
                gotoxy(x - 2, ++y);
                printf(">");

            }
            break;
        }
        case SUBMIT: {
            return y - 26;

        }
        }
    }
}