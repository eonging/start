#include <stdio.h>
#include <windows.h>

#define UP 0
#define DOWN 1
#define SUBMIT 4

int keyControl();
void init();
void titleDraw();
int menuDraw();
void gotoxy(int, int);

int main() {
    init();
    titleDraw();
    menuDraw();

    int keyCode = keyControl();
    printf("�Է��� Ű���� : %d �Դϴ�\n", keyCode);
    
    return 0;
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

void init() {
    system("mode con cols=100 lines=30 | title �� �� �� �� ");
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


void gotoxy(int x, int y) {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(consoleHandle, pos);
}

int menuDraw() {
    int x = 40;
    int y = 26;

    gotoxy(x - 2, 26);
    printf("> ���ӽ��� ");
    gotoxy(40, 27);
    printf("���ӱ�Ģ ");
    gotoxy(40, 28);
    printf("  ���� ");
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