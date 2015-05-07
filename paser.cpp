#include "osal.h"

void parser(string &origin, stock_report &rep)
{
	int index=0;
	string input(origin);
	int lpos,rpos=0;

	lpos=0;
	for(index=0;index<INFO_ITEM+1;index++)
	{
		rpos=input.find(",", lpos);
		string temp(input,lpos, rpos-lpos);
		if(index == 0)
			strcpy(rep.name, temp.c_str());
		else
			rep.info[index-1]=atof(temp.c_str());

		lpos=rpos+1;
	}

	return ;
}