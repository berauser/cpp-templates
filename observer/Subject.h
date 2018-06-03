
#ifndef SRC_SUBJECT_H_
#define SRC_SUBJECT_H_

#include <map>
#include <vector>
#include <functional>

template <typename Key, typename R, typename... Params>
class Subject
{
public:
	typedef std::function<R(Params...)> ObserverCallback;

public:
	void registerObserver(const Key& key, const ObserverCallback& callback)
	{
		if( _callbacks.find(key) == _callbacks.end() )
		{
			_callbacks.insert( std::pair<Key, std::vector<ObserverCallback>>(key, std::vector<ObserverCallback>()));
		}
		_callbacks[key].push_back(callback);
	}

	void unregisterAll(const Key& key)
	{
		auto it = _callbacks.find(key);
		if( it != _callbacks.end() )
		{
			_callbacks.erase(it);
		}
	}

	void notify(const Key& key, Params... params)
	{
		if( _callbacks.find(key) != _callbacks.end() )
		{
			for (ObserverCallback callback : _callbacks[key] )
			{
				callback(params...);
			}
		}
	}

protected:
	std::map<Key, std::vector<ObserverCallback>> _callbacks;
};

template <typename Key, typename R>
class Subject<Key,R>
{
public:
	typedef std::function<R()> ObserverCallback;

public:
	void registerObserver(const Key& key, const ObserverCallback& callback)
	{
		if( _callbacks.find(key) == _callbacks.end() )
		{
			_callbacks.insert( std::pair<Key, std::vector<ObserverCallback>>(key, std::vector<ObserverCallback>()));
		}
		_callbacks[key].push_back(callback);
	}

	void unregisterAll(const Key& key)
	{
		auto it = _callbacks.find(key);
		if( it != _callbacks.end() )
		{
			_callbacks.erase(it);
		}
	}

	void notify(const Key& key)
	{
		if( _callbacks.find(key) != _callbacks.end() )
		{
			for (ObserverCallback callback : _callbacks[key] )
			{
				callback();
			}
		}
	}

protected:
	std::map<Key, std::vector<ObserverCallback>> _callbacks;
};

#endif /* SRC_SUBJECT_H_ */