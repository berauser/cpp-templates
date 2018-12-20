
#ifndef SRC_REGISTRY_H_
#define SRC_REGISTRY_H_

#include <map>
#include <list>
#include <memory>
#include <functional>

/*******************************************************************************
 *
 * Generic excpetion for registry
 *
 * *****************************************************************************
 * Exception for undefined keys.
 * The Undefined key excpetion is thrown when the key is not registered
 * in the registry.
 */
template <typename Key>
class UndefinedKeyException : public std::exception
{
public:
	/**
	 * Constructor
	 * @param key The key that is not found in the registry
	 */
	UndefinedKeyException(const Key &key) : _key(key) {}
	/**
	 * Returns the excpetion description.
	 * @return Describtion of the exception.
	 */
	const char *what() const throw() { return "Key is not defined"; }
	/**
	 * Returns the key that is not registered.
	 * @return Key that is not registered.
	 */
	const Key key() const { return _key; }
private:
	const Key _key;  //!< key
};

/*******************************************************************************
 *
 * Generic registry base class
 *
 * *****************************************************************************
 * A generic registry
 * @tparam Base The base class sof the types that should be registered
 * @tparam Key  The key type to search for the registered class
 * @tparam Args The argument list types thats should be used to create the registered type
 */
template <typename Key, typename Func>
class Registry
{
public:
	/**
	 * Constructor function pointer
	 */
	typedef std::function<Func> function;

	Registry() = default;
	~Registry() = default;

	/**
	 * Register a derived class.
	 * @tparam Derived The type of the derived class that should be registered.
	 * @param key The key that should be used to find the type.
	 */
	void registerFunction(const Key &key, const function &func)
	{
		m_map[key] = func;
	}

	/**
	 * Unregister type.
	 * @param key The key of the registered type that should be unregistered.
	 */
	void unregisterFunction(const Key &key)
	{
		m_map.erase(key);
	}

	/**
	 * Check if a class is registered
	 * @param key The key of the type that should be checked
	 * @return true if registered, otherwise false
	 */
	bool isRegistered(const Key &key)
	{
		return (m_map.find(key) != m_map.end());
	}

	/**
	 * Get a list of keys of all registered types
	 * @return List of registered types
	 */
	std::list<Key> registeredKeys() const
	{
		std::list<Key> keys;
		for (auto k : m_map)
		{
			keys.push_back(k.first);
		}
		return keys;
	}

	/**
	 * Clears the registry
	 */
	void clear()
	{
		m_map.clear();
	}

	function& operator [](const Key &key)
    {
        try
		{
			return m_map.at(key);
		}
		catch (const std::out_of_range &e)
		{
			throw UndefinedKeyException<Key>(key);
		}
    }

private:
	std::map<Key, function> m_map;  //!< map of registered types
};

#endif /* SRC_REGISTRY_H_ */
