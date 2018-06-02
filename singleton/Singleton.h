
#include <mutex>

template<class T>
class Singleton
{
public:
	Singleton()
	{
	}
	
	~Singleton()
	{
	}
	
	T* operator->() const
	{
		return &_singleton;
	}
	
private:
	Singleton(const Singleton&) = delete;
	
private:
	static T _singleton;
	mutable std::mutex _mutex;
};

template<class T>
T Singleton<T>::_singleton;


