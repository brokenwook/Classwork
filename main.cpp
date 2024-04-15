

namespace test
{

	void print_error(int result, int expected)
	{
		std::cout << "Ожидалось:\t" << result << std::endl;
		std::cout << "Получено:\t" << expected << std::endl;
	}

	bool check_not_equal(int result, int expected)
	{
		return result != expected;
	}

	bool check_equal_element(std::vector<int> result_vec, std::vector<int> expect_vec)
	{
		for (int i = 0; i < expect_vec.size(); i++)
		{
			if (check_not_equal(result_vec[i], expect_vec[i]))
			{
				print_error(expect_vec[i], result_vec[i]);
				return false;
			}
		}
		return true;
	}

	void test_some_func(std::vector<int>(*creat_vec)(int))
	{
		int amount = 6;
		std::vector<int> expect_vec = {1,2,4,8,16,22};

		std::vector<int> result_vec = creat_vec(amount);

		std::cout << "1) Проверка кол-во элементов: ----- " << std::endl;
		if (check_not_equal(result_vec.size(), amount))
		{
			std::cout << "-------- Несоответствие кол-ва элементов вектора " << std::endl;
			print_error(amount, result_vec.size());
			return;
		}
		else {
			std::cout << "---------- Верное кол-во элементов " << std::endl;
		}
		std::cout <<  "2) Проверка cоответствия элементов: ----- " << std::endl;
		if (!check_equal_element(result_vec, expect_vec))
		{
			std::cout << "-------- Несоответствие элементов по индексу " << std::endl;
			return;
		}
		else {
			std::cout << "----- Все элементы содержат ожидаемое значния " << std::endl;
		}

		std::cout << "Функция работает корректно!\n";

	}
}
