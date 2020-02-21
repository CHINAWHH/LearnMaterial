#include "Common.h"

//C���Ե�Strcpy()�����������ڴ渲��
char * my_strcpy(char * strDest, const char * strSrc)
{
	assert((strDest != nullptr) && (strSrc != nullptr));
	char * pCharAdress = strDest;
	while ((*pCharAdress++ = *strSrc++) != '\0')
	{
	}
	return strDest;
}
//strcpy�ܰ�strSrc�����ݸ��Ƶ�strDest��Ϊʲô��Ҫchar * ���͵ķ���ֵ��
//��Ϊ��ʵ����ʽ���ʽ��                                    
//����       int length = strlen(strcpy(strDest, ��hello world��));
//�����ڴ渲��

char * newMy_Strcpy(char *strDest, const char *strSrc)
{
	assert((strDest != nullptr) && (strSrc != nullptr));
	size_t len = strlen(strSrc);
	if (strDest < strSrc || strSrc + len <= strDest)
	{
		char * pResult = strDest;
		while (len--)
		{
			*pResult++ = *strSrc++;
		}
	}
	else
	{
		char * pResult = strDest;
		pResult += len;
		strSrc += len;
		while (len--)
		{
			*pResult-- = *strSrc--;
		}
	}
	return strDest;
}

char * my_strCat(char * pre, const char * next)
{
	assert((pre != nullptr) && (next != nullptr));
	size_t len = strlen(pre);
	char * pTemp = pre + len;
	while ((*pTemp++ = *next++) != '\0')
	{
	}
	return pre;
}

char * my_strnpy(char * strDest, const char *strSrc, size_t len)
{
	assert((strDest != nullptr) && (strSrc != nullptr));
	char * pTemp = strDest;
	while ((*pTemp++ = *strSrc++) != '\0'&&len)
	{
		--len;
	}
	if (len)
	{
		while (len--)
		{
			*pTemp++ = '\0';
		}
	}
	return strDest;
}

void * my_memcpy(void * pDes, const void * pSrc, size_t len)
{
	assert((pDes != nullptr) && (pSrc != nullptr));
	char * pTempDes = (char *)pDes;
	const char * pTempSrc = (const char *)pSrc;
	while (len--)
	{
		*pTempDes++ = *pTempSrc++;
	}
	return pDes;
}