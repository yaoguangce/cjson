/*
 * @Author: yaogc
 * @Date: 2021-11-17 14:23:35
 * @LastEditTime: 2021-11-18 09:23:50
 * @LastEditors: Please set LastEditors
 * @FilePath: /c_json/main.c
 */
#include <stdio.h>
#include "cJSON.h"
int main(int argc, const char *argv[])
{
	cJSON *AnalysisJson = NULL;
	//	char str[128]= "{\"control\":{\"io_out_3\":true}}";
	char str[128] = "{\"control\":{\"pwm_out_1\":{\"frequency\":122,\"ratio\":1232}}}";
	AnalysisJson = cJSON_Parse(str);
	if (AnalysisJson)
	{
		/******************************解析未知格式json字串***********************/
		printf("解析未知格式json字串\n");
		cJSON *pCjson = AnalysisJson->child;
		while (pCjson)
		{
			switch(pCjson->type)
			{
			case cJSON_False:
				printf("%s %d\n",pCjson->string,pCjson->valueint);
				break;
			case cJSON_True:
				printf("%s %d\n",pCjson->string,pCjson->valueint);
				break;
			case cJSON_NULL:
				printf("%s\n",pCjson->string);
				break;
			case cJSON_Number:
				printf("%s,%f\n",pCjson->string,pCjson->valuedouble );
				break;
			case cJSON_String:
				printf("%s,%s\n",pCjson->string,pCjson->valuestring );
				break;
			case cJSON_Array:
				{
					/**************解析json数组******************/
					//json数组pCjson的子节点是json对象
					//获取json对象pChild
					cJSON * pArrChild = pCjson->child;
					if (pArrChild)
					{
						cJSON * ppACChild = pArrChild->child;
						while (ppACChild)
						{
							switch(ppACChild->type)
							{
							case cJSON_False:
								printf("%s %d\n",ppACChild->string,ppACChild->valueint);
								break;
							case cJSON_True:
								printf("%s,%d\n",ppACChild->string,ppACChild->valueint );
								break;
							case cJSON_NULL:
								printf("%s\n",ppACChild->string);
								break;
							case cJSON_Number:
								printf("%s,%d\n",ppACChild->string,ppACChild->valueint );
								break;
							case cJSON_String:
								printf("%s,%s\n",ppACChild->string,ppACChild->valuestring );
								break;
							}
							ppACChild = ppACChild->next;
						}
					}
				}
				break;
			case cJSON_Object:
				printf("\n");
				cJSON * pArrChild = pCjson->child;
				if (pArrChild)
				{
					while (pArrChild)
					{
						switch(pArrChild->type)
						{
						case cJSON_False:
							printf("%s %d\n",pArrChild->string,pArrChild->valueint);
							break;
						case cJSON_True:
							printf("%s,%d\n",pArrChild->string,pArrChild->valueint );
							break;
						case cJSON_NULL:
							printf("%s\n",pArrChild->string);
							break;
						case cJSON_Number:
							printf("%s,%d\n",pArrChild->string,pArrChild->valueint );
							break;
						case cJSON_String:
							printf("%s,%s\n",pArrChild->string,pArrChild->valuestring );
							break;
						case cJSON_Object:
							printf("cJSON_Object暂时未解析\n");
							cJSON * ppACChild = pArrChild->child;
							while (ppACChild)
							{
								switch(ppACChild->type)
								{
								case cJSON_False:
									printf("%s %d\n",ppACChild->string,ppACChild->valueint);
									break;
								case cJSON_True:
									printf("%s,%d\n",ppACChild->string,ppACChild->valueint );
									break;
								case cJSON_NULL:
									printf("%s\n",ppACChild->string);
									break;
								case cJSON_Number:
									printf("%s,%d\n",ppACChild->string,ppACChild->valueint );
									break;
								case cJSON_String:
									printf("%s,%s\n",ppACChild->string,ppACChild->valuestring );
									break;
								}
								ppACChild = ppACChild->next;
							}
						}
						break;
					}
					pArrChild = pArrChild->next;
				}
			}
			pCjson = pCjson->next;
		}
	}
	return 0;
}
