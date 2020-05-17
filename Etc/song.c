#include <windows.h> // WinApi header
#define G 783.991
#define A 880.000
#define B 987.767
#define Ch 1046.50
#define Dh 1174.66
#define Eh 1318.51
#define Fh 1396.91
#define Gh 1567.98
#define godsing Beep
int main()
{
    godsing(G,300);
    godsing(G,300);
    godsing(A,400);
    godsing(G,500);
    godsing(Ch,500);
    godsing(B,700);

    godsing(G,300);
    godsing(G,300);
    godsing(A,400);
    godsing(G,500);
    godsing(Dh,500);
    godsing(Ch,700);

    godsing(G,300);
    godsing(G,300);
    godsing(Gh,500);
    godsing(Eh,400);
    godsing(Ch,500);
    godsing(B,500);
    godsing(A,700);

    godsing(Fh,300);
    godsing(Fh,300);
    godsing(Eh,400);
    godsing(Ch,500);
    godsing(Dh,500);
    godsing(Ch,700);

}
