/*************************************************************************
	> File Name: Sales_item.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Thu 09 Jul 2015 04:45:54 PM CST
 ************************************************************************/

#include<iostream>
//using namespace std;
#include"Sales_item.h"
int main()
{
	Sales_item total,trans;
	if(std::cin >> total){
		while(std::cin >>trans){
			if(total.same_isbn(trans))
				total = total + trans;
			else{
				std::cout << total << std::endl;
				total = trans;
			}
		}
		std::cout << total << std::endl;
	}
	else{
		std::cout << "No data" << std::endl;
		return -1;
	}
	return 0;
}
