#include <log4cplus/logger.h>
#include <log4cplus/configurator.h>
#include <iomanip>
#include <log4cplus/logger.h>
#include <log4cplus/fileappender.h>
#include <log4cplus/consoleappender.h>
#include <log4cplus/layout.h>
#include <time.h>
#include <string>
#include <string.h>
#include <stdlib.h>

using namespace std;
using namespace log4cplus;
Logger pTestLogger;
void writelog(char* leval,char* info)
{
	struct tm *p;
	time_t lt=time(NULL);
	p=localtime(&lt);
	char* timetemp=ctime(&lt);
	*(timetemp+strlen(timetemp)-1)='\0';
	char temp[10000];
	sprintf(temp,"[%s] %s",timetemp,info);
			printf("temp==%s",temp);
	printf("leval====%s ",leval);
	if(memcmp(leval,"TRACE",5)==0)
	printf("%d===%d",memcmp("TRACE","TRAC1E",5),memcmp(leval,"TRACE",5));
	LOG4CPLUS_TRACE(pTestLogger,temp);
	if(memcmp(leval,"DEBUG",5)==0)
	LOG4CPLUS_DEBUG(pTestLogger,temp);
	if(memcmp(leval,"INFO",4)==0)
	LOG4CPLUS_INFO(pTestLogger,temp);
	if(memcmp(leval,"WARN",4)==0)
	LOG4CPLUS_WARN(pTestLogger,temp);
	if(memcmp(leval,"ERROR",5)==0)
	LOG4CPLUS_ERROR(pTestLogger,temp);
	if(memcmp(leval,"FATAL",5)==0)
	LOG4CPLUS_FATAL(pTestLogger,temp);
}
int main()
{
	char* info="you have a iuns";
	char filename[50];
	struct tm *p;
	time_t lt=time(NULL);
	p=localtime(&lt);
	sprintf(filename,"%d-%d-%d.txt",(1900+p->tm_year), (1+p->tm_mon),p->tm_mday);
	FILE* stream=fopen(filename,"wb");
	SharedAppenderPtr pFileAppender(new FileAppender((filename)));
	pTestLogger = Logger::getInstance(("LoggerName"));
	pTestLogger.addAppender(pFileAppender);
	//writelog("TRACE",info);
	//writelog("DEBUG",info);
	//writelog("ERROR",info);
	char* timetemp=ctime(&lt);
	*(timetemp+strlen(timetemp)-1)='\0';
	char temp[10000];
	sprintf(temp,"[%s] %s",timetemp,info);
	LOG4CPLUS_FATAL(pTestLogger,temp);
	
	return 0;
}
