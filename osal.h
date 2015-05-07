#ifndef __STOCK_OSAL_H
#define __STOCK_OSAL_H


#include <stdio.h>
#include <stdlib.h>
#include <iostream>  
#include <string>  
#include "event2/event.h"
#include "event2/bufferevent.h"
#include "event2/buffer.h"
#include <WinSock2.h>
#include <errno.h>
#include <string.h>
#include "event2/http.h"
#include "event2/http_struct.h"
#include "event2/keyvalq_struct.h"
#include "event2/dns.h"  
using namespace std;


struct download_context{  
    struct evhttp_uri * uri;  
    struct event_base * base;  
    struct evdns_base * dnsbase;  
    struct evhttp_connection * conn;  
    struct evhttp_request *req;  
    struct evbuffer *buffer;  
    int ok;  
};  


#define INFO_ITEM 10
typedef struct 
{
	char name[100];
	union
	{
		struct 
		{
			float today_open;
			float yesterday_close;
			float current;
			float top;
			float bottom;
			float buy_one;
			float sell_one;
			float turnover_hands;
			float turnover_money;
		}_data;
		float info[INFO_ITEM];
	};
}stock_report;


void parser(string &origin, stock_report &rep);
#endif


