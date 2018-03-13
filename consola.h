#include <conio.h>
#include <windows.h>

struct TEntity;

/*
	Copied from Ejercicio2
*/
void gotoxy			(int x, int y);
void hidecursor	(void);
void clear			();

/*
	Added for P4
*/
void MoveEntity(TEntity *e);
void PaintEntity(TEntity *e);