void findLongestSubstring(const char a[], const char b[], char res[]) 
{	
	int max_len = 0;	//	максимальный размер общей строки
	res[max_len] = '\0';
	for (int i = 0; a[i]; i++)
	{	//	идем по каждому символу первой строки
		for (int j = 0, k = 0; b[j]; j++)
		{	//	и пока каждому символу второй строки
			if (a[i + k] == b[j])
			{	//	если символы совпадают
				k++;	//	прибавляем счетчик совпадающих символов
				if (a[i + k] != b[j + 1] || b[j + 1] == '\0')
				{	//	если следующий символ уже расходится	
					if (k > max_len)
					{	//	если прошлая общая строка была меньшего размера
						for (int s = 1; s <= k; s++)	//	записываем посимвольно новый результат
							res[s - 1] = b[j - k + s];
						res[k] = '\0';	//	завершаем результирующую строку
						max_len = k;	//	новый размер максимальной строки
						break;
					}
					j++;	//	пропускаем один символ т к уже знаем что он не совпадает
					k = 0;	//	обнуляем счетчик совпадающих символов 
				}
			}
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{	
	char res[128];
	findLongestSubstring("acge1234jlk", "eg2341ilka", res);
	std::cout << res << std::endl;
	
	findLongestSubstring("1234", "56789", res);
	std::cout << res << std::endl;
	
	findLongestSubstring("dhjkqlsae", "kjhdsrd", res);
	std::cout << res << std::endl;
	
	return 0;
}
