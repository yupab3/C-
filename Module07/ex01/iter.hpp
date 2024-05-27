#ifndef	ITER_HPP
# define ITER_HPP

template<typename T, typename F>
void	iter(T*	arr, size_t length, F func)
{
	for(size_t i = 0; i < length; i++)
	{
		// (*arr)++;
		func(*(arr + i));
	}
}

template<typename T>
void    funcTemplate(T a)
{
    std::cout << "instanced template func, " << a;
    const std::type_info& type = typeid(a);
	std::cout << ", type = " << type.name() << '\n';
}

#endif
