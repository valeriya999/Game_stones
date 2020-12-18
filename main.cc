#include <iostream>
#include <string>
#include <random>
#include <sstream>

std::random_device rd;
std::ranlux48 rnd { rd() };
std::uniform_int_distribution<> dist1 {15, 25};
std::uniform_int_distribution<> dist2 {1, 3};

int read_answer()
{
    int result;
    std::cout <<"�������� �� 1 �� 3 ������" << std::endl;
    std::string input;
    std::getline(std::cin, input);
    std::stringstream input_ss { input };
    input_ss >> result;
    bool f = input_ss.fail();
    while ( f || result < 1 || result > 3) {//��������� ������������ ����� ��������� ������
        std::cerr << "�������� ����, ����� ����� ������ �� 1 �� 3 ������. ���������� ��� ���: " << std::endl;
    	std::getline(std::cin, input);
    	std::stringstream input_ss { input };
        input_ss >> result;
        f = input_ss.fail();
    }
    return result;
}


int lvl_1(bool f)
{
	int d1 = dist1(rnd);
	std::cout << "����� " << d1 << " ������" << std::endl;
	int d2, a;
	bool f1;
	for (unsigned i=0; d1>0; ++i)
	{
		if( i%2 == 0 )
	    {
	        a = read_answer();
	        while (a > d1)
	        {
	        	std::cerr << "����� �������� " << d1 << " ������. �������� ������ �����!" << std::endl;
	        	a = read_answer();
	        }
	        std::cout << "�������� " <<(d1 - a) <<" ������ " << std::endl;
	        d1 -= a;
	        f1 = true;
	    }
	    else
	    {
	    	d2 = dist2 (rnd);
	    	while (d2 > d1)
	    	{
	    		d2 = dist2 (rnd);
	    	}
	        std::cout << "��������� ���� ������ - " << d2 << ". ������ ��������: " << (d1-d2) << std::endl;
	        d1 -= d2;
	        f1 = false;
	    }
			if (d1 < 13 and f) return d1;
	    }
	if(f1) std::cout << "���� ��������. ������� ���������!" << std::endl;
	else std::cout << "���� ��������. �� ��������!!!!!!" << std::endl;
	return 1;
}


void lvl_3(bool f, int ans)
{
	int d1 = ans;
	std::cout << "����� " << d1 << " ������" << std::endl;
	int d2, a;//��� ���������� ���� �����
	bool f1;
	for (unsigned i=0; d1>0; ++i)
	{
		if(i%2 == 0)
	    {
	        a = read_answer();//����� ������������ ������� ������ �����
	        while (a > d1)
	        {
	        	std::cerr << "����� �������� " << d1 << " ������. �������� ������ �����!";
	        	a = read_answer();
	        }
	        std::cout << "�������� " <<(d1 - a) <<" ������ " << std::endl;
	        d1 -= a;
	        f1 = true;
	    }

	    else
	    {
	        if( d1 % 4 == 2 )
			{
	    		d1 -= 1;
	    		std::cout << "��������� ���� ������ - 1" << ". ������ ��������: " << d1 << std::endl;
	    	}

	    	else if( d1 % 4 == 3 )
	    	{
	    		d1 -= 2;
	    		std::cout << "��������� ���� ������ - 2" << ". ������ ��������: " << d1 << std::endl;
	    	}

	    	else if( d1 % 4 == 0 )
	    	{
	    		d1 -= 3;
	    		std::cout << "��������� ���� ������ - 3" << ". ������ ��������: " << d1 << std::endl;
	    	}

	    	else
	    	{
	    		d2 = dist2 (rnd);
	    		while (d2 > d1)
	    		{
	    			d2 = dist2 (rnd);
	    		}
	    		d1 -= d2;
	    		std::cout << "Random choise - " << d2 << ". ������ ��������: " << d1 << std::endl;
	    	}
	    	f1 = false;
	    }
	}
	if(f1) std::cout << "���� ��������. ������� ���������!" << std::endl;
	else std::cout << "���� ��������. �� ��������!!!!!!" << std::endl;
}


void lvl_2()
{
	bool f = true;
	int ans = lvl_1(f);
	lvl_3(f, ans);
}


int main()
{
	int choise;
	bool f = false;

	do
	{
		std::cout << "������� ������� ��������� : " << std::endl
				  << "1. ������" << std::endl
				  << "2. �������" << std::endl
			      << "3. �������" << std::endl
				  << "4. �����" << std::endl;
		std::cin >> choise;
		while (std::cin.fail() or choise < 1 or choise > 4)
		    {
				std::cerr << "������������ ����. ���������� ��� ��� :" << std::endl;
		        if (std::cin.fail()) //
		        {
		            std::cin.clear();
		            std::cin.ignore(32767,'\n');
		        }
		        std::cin >> choise;
		    }
		std::cin.ignore(32767,'\n');

		switch(choise){
			case 1: {lvl_1(f); break;}
			case 2:	{lvl_2(); break;}
			case 3:	{lvl_3(f, dist1(rnd)); break;}

		}
	}while (choise != 4);

    return 0;
}
