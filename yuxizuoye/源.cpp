#include <iostream>
#include<conio.h>
bool Isgameover(int* map, int Rbox)     //Rbox 为目的地个数
{
	int n = 0;
	for (int i = 0; i < 100; i++)
	{
		if (*(map + i) == 6)
		{
			n++;
		}
	}
	if (Rbox == n)
	{
		std::cout << "恭喜通关！！！\n";
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	int input;						//输入常数
	int nowpoint = 31;				//玩家现在的地点
	int shift;                       //玩家目标点
	const int w = 10;                  //地图宽度
	int map[100] =                   
	{
		1,1,1,1,1,1,1,1,1,1,
		1,0,0,0,0,0,0,0,0,1,
		1,0,0,0,3,0,4,0,0,1,
		1,2,0,0,0,0,1,1,1,1,
		1,0,0,0,0,0,0,0,0,1,
		1,0,1,3,1,4,0,0,0,1,
		1,0,0,0,0,0,0,0,0,1,
		1,0,0,0,3,0,0,0,0,1,
		1,0,0,0,0,0,0,4,0,1,
		1,1,1,1,1,1,1,1,1,1
	};
	while (true)
	{
		system("cls");
		for (int i = 0; i < 100; i++)
		{
			switch (map[i])
			{
			case 1:std::cout << "□"; break;     //墙壁
			case 0:std::cout << "  "; break;     //空地
			case 2:std::cout << "Pe"; break;     //人
			case 3:std::cout << "■"; break;    //箱子
			case 4:std::cout << "**"; break;    //箱子目的地
			case 5:std::cout << "×"; break;    //和人重合
			case 6:std::cout << "√"; break;    //和箱子重合
			}
			if (i % w == 9)
				std::cout << '\n';
		}
		if (Isgameover(map, 3))
		{
			break;
		}
		input = _getch();


		//往上
		if (input == 'w' || input == 'W')
		{
			shift = map[nowpoint - w];         //下一个移动的目标点设置给shift
			if (shift == 0)                    //当下一个目标是空地的时候
			{
				if (map[nowpoint] == 5)       //当和箱子目标点重合的时候且需要移动到空地
				{
					map[nowpoint] = 2;               //当前坐标设置为玩家
					map[nowpoint - w] = map[nowpoint];    //下一个坐标为玩家
					map[nowpoint] = 4;              //当前坐标为箱子目标点
					nowpoint -= w;                  //移动当前坐标
				}
				else                        //如果没有和箱子目标点重合，则正常移动
				{
					map[nowpoint - w] = map[nowpoint];
					map[nowpoint] = shift;
					nowpoint -= w;
				}
			}
			else if (shift == 4)                  //当下一个个目标点为箱子目标点时
			{
				map[nowpoint - w] = 5;            //目标点变为人和箱子重合的图案
				map[nowpoint] = 0;                //当前点变为空地
				nowpoint -= w;                    //移动人物的坐标
			}
			else if (shift == 6 && map[nowpoint - 2 * w] != 1)                  //如果下一个点为箱子和箱子的目标点重合
			{
				map[nowpoint - 2 * w] = 3;                     //目标点的下一个点变为箱子
				map[nowpoint - w] = 5;                       //下一个点变为和人重合
				map[nowpoint] = 0;                           //人物当前点变为空地
				nowpoint -= w;
			}
			else if (shift == 3)                    //目标点为箱子
			{
				if (map[nowpoint - 2 * w] != 1 && map[nowpoint - 2 * w] != 3 && map[nowpoint - 2 * w] != 6)         //箱子的下一个目标点不能是墙壁，或者箱子
				{
					if (map[nowpoint - 2 * w] == 4)                     //箱子的下一个目标点是箱子目的地
					{
						map[nowpoint - 2 * w] = 6;                       //箱子的下一个目标点变为和箱子重合
						map[nowpoint - w] = map[nowpoint];             //箱子的位置变为玩家位置
						map[nowpoint] = 0;                             //玩家为之变为空地
						nowpoint -= w;                                 //移动玩家坐标
					}
					else if (map[nowpoint] == 5)                       //目标点为箱子，并且玩家处在箱子目标点里面
					{
						map[nowpoint - w] = map[nowpoint - 2 * w];         //箱子向上
						map[nowpoint - 2 * w] = shift;                  // 箱子目标点变为人物目标点
						map[nowpoint - w] = 2;                        //箱子位置变为玩家
						map[nowpoint] = 4;							//玩家上一个点变为箱子目的地
						nowpoint -= w;
					}
					else                                          //其他情况自由移动
					{
						map[nowpoint - 2 * w] = shift;             //箱子的目标点变为箱子
						map[nowpoint - w] = map[nowpoint];       //玩家目标点变为玩家
						map[nowpoint] = 0;						//玩家下面的点变为空地
						nowpoint -= w;							//移动玩家点
					}
				}
			}


		}
		//往下
		else if (input == 's' || input == 'S')
		{
			shift = map[nowpoint + w];
			if (shift == 0)
			{
				if (map[nowpoint] == 5)
				{
					map[nowpoint] = 2;
					map[nowpoint + w] = map[nowpoint];
					map[nowpoint] = 4;
					nowpoint += w;
				}
				else
				{
					map[nowpoint + w] = map[nowpoint];
					map[nowpoint] = shift;
					nowpoint += w;
				}

			}
			else if (shift == 4)
			{
				map[nowpoint + w] = 5;
				map[nowpoint] = 0;
				nowpoint += w;
			}
			else if (shift == 6 && map[nowpoint + 2 * w] != 1)
			{
				map[nowpoint + 2 * w] = 3;
				map[nowpoint + w] = 5;
				map[nowpoint] = 0;
				nowpoint += w;
			}
			else if (shift == 3)
			{
				if (map[nowpoint + 2 * w] != 1 && map[nowpoint + 2 * w] != 3 && map[nowpoint + 2 * w] != 6)
				{
					if (map[nowpoint + 2 * w] == 4)
					{
						map[nowpoint + 2 * w] = 6;
						map[nowpoint + w] = map[nowpoint];
						map[nowpoint] = 0;
						nowpoint += w;
					}
					else if (map[nowpoint] == 5)
					{
						map[nowpoint + w] = map[nowpoint + 2 * w];
						map[nowpoint + 2 * w] = shift;
						map[nowpoint + w] = 2;
						map[nowpoint] = 4;
						nowpoint += w;
					}
					else
					{
						map[nowpoint + 2 * w] = shift;
						map[nowpoint + w] = map[nowpoint];
						map[nowpoint] = 0;
						nowpoint += w;
					}
				}

			}
		}


		//往左
		else if (input == 'a' || input == 'A')
		{
			shift = map[nowpoint - 1];
			if (shift == 0)
			{
				if (map[nowpoint] == 5)
				{
					map[nowpoint] = 2;
					map[nowpoint - 1] = map[nowpoint];
					map[nowpoint] = 4;
					nowpoint -= 1;
				}
				else
				{
					map[nowpoint - 1] = map[nowpoint];
					map[nowpoint] = shift;
					nowpoint -= 1;
				}
			}
			else if (shift == 4)
			{
				map[nowpoint - 1] = 5;
				map[nowpoint] = 0;
				nowpoint -= 1;
			}
			else if (shift == 6 && map[nowpoint - 2] != 1)
			{
				map[nowpoint - 2] = 3;
				map[nowpoint - 1] = 5;
				map[nowpoint] = 0;
				nowpoint -= 1;
			}
			else if (shift == 3)
			{
				if (map[nowpoint - 2] != 1 && map[nowpoint - 2] != 3 && map[nowpoint - 2] != 6)
				{
					if (map[nowpoint - 2] == 4)
					{
						map[nowpoint - 1] = map[nowpoint - 2];
						map[nowpoint - 2] = 6;
						map[nowpoint - 1] = map[nowpoint];
						map[nowpoint] = 0;
						nowpoint -= 1;
					}
					else if (map[nowpoint] == 5)
					{
						map[nowpoint - 1] = map[nowpoint - 2];
						map[nowpoint - 2] = shift;
						map[nowpoint - 1] = 2;
						map[nowpoint] = 4;
						nowpoint -= 1;
					}
					else
					{
						map[nowpoint - 2] = shift;
						map[nowpoint - 1] = map[nowpoint];
						map[nowpoint] = 0;
						nowpoint -= 1;
					}

				}

			}

		}
		//往右
		else if (input == 'd' || input == 'D')
		{
			shift = map[nowpoint + 1];
			if (shift == 0)
			{
				if (map[nowpoint] == 5)
				{

					map[nowpoint] = 2;
					map[nowpoint + 1] = map[nowpoint];
					map[nowpoint] = 4;
					nowpoint += 1;
				}
				else
				{
					map[nowpoint + 1] = map[nowpoint];
					map[nowpoint] = shift;
					nowpoint += 1;
				}
			}
			else if (shift == 4)
			{
				map[nowpoint + 1] = 5;
				map[nowpoint] = 0;
				nowpoint += 1;
			}
			else if (shift == 6 && map[nowpoint + 2] != 1)
			{
				map[nowpoint + 2] = 3;
				map[nowpoint + 1] = 5;
				map[nowpoint] = 0;
				nowpoint += 1;
			}
			else if (shift == 3)
			{
				if (map[nowpoint + 2] != 1 && map[nowpoint + 2] != 3 && map[nowpoint + 2] != 6)
				{
					if (map[nowpoint + 2] == 4)
					{
						map[nowpoint + 1] = map[nowpoint + 2];
						map[nowpoint + 2] = 6;
						map[nowpoint + 1] = map[nowpoint];
						map[nowpoint] = 0;
						nowpoint += 1;
						std::cout << "!!!";
					}
					else if (map[nowpoint] == 5)
					{
						map[nowpoint + 1] = map[nowpoint + 2];
						map[nowpoint + 2] = shift;
						map[nowpoint + 1] = 2;
						map[nowpoint] = 4;
						nowpoint += 1;
						std::cout << "!!";
					}
					else
					{
						map[nowpoint + 2] = shift;
						map[nowpoint + 1] = map[nowpoint];
						map[nowpoint] = 0;
						nowpoint += 1;
						std::cout << "!";
					}
				}
			}
		}
	}
	system("pause");
	return 0;

}