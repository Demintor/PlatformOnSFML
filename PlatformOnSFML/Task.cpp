#include "Task.h"

int damage = 0;
bool ifDamage = false;
bool endGame = false;

vector<TaskAndDoors> taskDoor{ { 0,'a' },{ 1,'c' },{ 2,'d' },{ 3,'e' },{ 4,'f' } };

Task::Task(int idTask) {
	textTask.loadFromFile(imgTaks[idTask]);
	spriteTask.setTexture(textTask);
	spriteTask.setPosition(5, 5);
	onTask = true;
}

void Task::Crutch() {
	while (Keyboard::isKeyPressed(Keyboard::Num1) || Keyboard::isKeyPressed(Keyboard::Num2) || Keyboard::isKeyPressed(Keyboard::Num3) || Keyboard::isKeyPressed(Keyboard::Num4)) {}
}

void Task::OpenDoor(char door) {
	for (int i = 0; i<H; i++)
		for (int j = 0; j < W; j++) {
			if (TileMap[i][j] == door) {
				TileMap[i][j] = 'o';
				for (int k = i + 1; k < i + 5; k++) {
					TileMap[k][j] = ' ';
				}
			}
			else
				continue;

		}

}

void Task::ResTask(int idTask) {
	switch (idTask) {
	case 0:
		if (Keyboard::isKeyPressed(Keyboard::Num1)) {
			Crutch();
			OpenDoor(taskDoor[idTask].idDoor);
			damage += 5000;
			onTask = false;
			ifDamage = true;
		}
		else
			if (Keyboard::isKeyPressed(Keyboard::Num2) || Keyboard::isKeyPressed(Keyboard::Num3) || Keyboard::isKeyPressed(Keyboard::Num4)) {
				Crutch();
				damage -= 5000;
				ifDamage = true;
			}

		break;

	case 1:
		if (Keyboard::isKeyPressed(Keyboard::Num2)) {
			Crutch();
			OpenDoor(taskDoor[idTask].idDoor);
			damage += 5000;
			onTask = false;
			ifDamage = true;
		}
		else
			if (Keyboard::isKeyPressed(Keyboard::Num1) || Keyboard::isKeyPressed(Keyboard::Num3) || Keyboard::isKeyPressed(Keyboard::Num4)) {
				Crutch();
				damage -= 5000;
				ifDamage = true;
			}
		break;

	case 2:
		if (Keyboard::isKeyPressed(Keyboard::Num3)) {
			Crutch();
			OpenDoor(taskDoor[idTask].idDoor);
			damage += 5000;
			onTask = false;
			ifDamage = true;
		}
		else
			if (Keyboard::isKeyPressed(Keyboard::Num1) || Keyboard::isKeyPressed(Keyboard::Num2) || Keyboard::isKeyPressed(Keyboard::Num4)) {
				Crutch();
				damage -= 5000;
				ifDamage = true;
			}

		break;

	case 3:
		if (Keyboard::isKeyPressed(Keyboard::Num1)) {
			Crutch();
			OpenDoor(taskDoor[idTask].idDoor);
			damage += 5000;
			onTask = false;
			ifDamage = true;
		}
		else
			if (Keyboard::isKeyPressed(Keyboard::Num2) || Keyboard::isKeyPressed(Keyboard::Num3) || Keyboard::isKeyPressed(Keyboard::Num4)) {
				Crutch();
				damage -= 5000;
				ifDamage = true;
			}

		break;

	case 4:
		if (Keyboard::isKeyPressed(Keyboard::Num4)) {
			Crutch();
			OpenDoor(taskDoor[idTask].idDoor);
			damage += 5000;
			onTask = false;
			ifDamage = true;
		}
		else
			if (Keyboard::isKeyPressed(Keyboard::Num1) || Keyboard::isKeyPressed(Keyboard::Num2) || Keyboard::isKeyPressed(Keyboard::Num3)) {
				Crutch();
				damage -= 5000;
				ifDamage = true;
			}

		break;
	case 5:
		if (Keyboard::isKeyPressed(Keyboard::Num3)) {
			Crutch();
			damage += 5000;
			endGame = true;
			onTask = false;
			ifDamage = true;
			endGame = true;
		}
		else
			if (Keyboard::isKeyPressed(Keyboard::Num1) || Keyboard::isKeyPressed(Keyboard::Num2) || Keyboard::isKeyPressed(Keyboard::Num4)) {
				Crutch();
				damage -= 5000;
				ifDamage = true;
			}

		break;

	default:
		break;
	}

}

Task::~Task() { }
