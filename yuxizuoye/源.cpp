#include <iostream>
#include<conio.h>
bool Isgameover(int* map, int Rbox)     //Rbox ΪĿ�ĵظ���
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
		std::cout << "��ϲͨ�أ�����\n";
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	int input;						//���볣��
	int nowpoint = 31;				//������ڵĵص�
	int shift;                       //���Ŀ���
	const int w = 10;                  //��ͼ���
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
			case 1:std::cout << "��"; break;     //ǽ��
			case 0:std::cout << "  "; break;     //�յ�
			case 2:std::cout << "Pe"; break;     //��
			case 3:std::cout << "��"; break;    //����
			case 4:std::cout << "**"; break;    //����Ŀ�ĵ�
			case 5:std::cout << "��"; break;    //�����غ�
			case 6:std::cout << "��"; break;    //�������غ�
			}
			if (i % w == 9)
				std::cout << '\n';
		}
		if (Isgameover(map, 3))
		{
			break;
		}
		input = _getch();


		//����
		if (input == 'w' || input == 'W')
		{
			shift = map[nowpoint - w];         //��һ���ƶ���Ŀ������ø�shift
			if (shift == 0)                    //����һ��Ŀ���ǿյص�ʱ��
			{
				if (map[nowpoint] == 5)       //��������Ŀ����غϵ�ʱ������Ҫ�ƶ����յ�
				{
					map[nowpoint] = 2;               //��ǰ��������Ϊ���
					map[nowpoint - w] = map[nowpoint];    //��һ������Ϊ���
					map[nowpoint] = 4;              //��ǰ����Ϊ����Ŀ���
					nowpoint -= w;                  //�ƶ���ǰ����
				}
				else                        //���û�к�����Ŀ����غϣ��������ƶ�
				{
					map[nowpoint - w] = map[nowpoint];
					map[nowpoint] = shift;
					nowpoint -= w;
				}
			}
			else if (shift == 4)                  //����һ����Ŀ���Ϊ����Ŀ���ʱ
			{
				map[nowpoint - w] = 5;            //Ŀ����Ϊ�˺������غϵ�ͼ��
				map[nowpoint] = 0;                //��ǰ���Ϊ�յ�
				nowpoint -= w;                    //�ƶ����������
			}
			else if (shift == 6 && map[nowpoint - 2 * w] != 1)                  //�����һ����Ϊ���Ӻ����ӵ�Ŀ����غ�
			{
				map[nowpoint - 2 * w] = 3;                     //Ŀ������һ�����Ϊ����
				map[nowpoint - w] = 5;                       //��һ�����Ϊ�����غ�
				map[nowpoint] = 0;                           //���ﵱǰ���Ϊ�յ�
				nowpoint -= w;
			}
			else if (shift == 3)                    //Ŀ���Ϊ����
			{
				if (map[nowpoint - 2 * w] != 1 && map[nowpoint - 2 * w] != 3 && map[nowpoint - 2 * w] != 6)         //���ӵ���һ��Ŀ��㲻����ǽ�ڣ���������
				{
					if (map[nowpoint - 2 * w] == 4)                     //���ӵ���һ��Ŀ���������Ŀ�ĵ�
					{
						map[nowpoint - 2 * w] = 6;                       //���ӵ���һ��Ŀ����Ϊ�������غ�
						map[nowpoint - w] = map[nowpoint];             //���ӵ�λ�ñ�Ϊ���λ��
						map[nowpoint] = 0;                             //���Ϊ֮��Ϊ�յ�
						nowpoint -= w;                                 //�ƶ��������
					}
					else if (map[nowpoint] == 5)                       //Ŀ���Ϊ���ӣ�������Ҵ�������Ŀ�������
					{
						map[nowpoint - w] = map[nowpoint - 2 * w];         //��������
						map[nowpoint - 2 * w] = shift;                  // ����Ŀ����Ϊ����Ŀ���
						map[nowpoint - w] = 2;                        //����λ�ñ�Ϊ���
						map[nowpoint] = 4;							//�����һ�����Ϊ����Ŀ�ĵ�
						nowpoint -= w;
					}
					else                                          //������������ƶ�
					{
						map[nowpoint - 2 * w] = shift;             //���ӵ�Ŀ����Ϊ����
						map[nowpoint - w] = map[nowpoint];       //���Ŀ����Ϊ���
						map[nowpoint] = 0;						//�������ĵ��Ϊ�յ�
						nowpoint -= w;							//�ƶ���ҵ�
					}
				}
			}


		}
		//����
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


		//����
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
		//����
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