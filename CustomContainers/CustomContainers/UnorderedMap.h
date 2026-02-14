#pragma once

#include <math.h>
#include <vector>
#include <functional>	

template<typename KeyType, typename ValueType>

class UnorderedMap
{
private:
	struct KeyValuePair
	{
		KeyType key;
		ValueType value;
	};
public:
	UnorderedMap(std::size_t initialBucketSize = 8, double loadFactor = 0.75)
		: mLoadFactorThreshold(loadFactor), mCount(0)
	{
		// in case we set it to 0
		mBucketCount = std::max<std::size_t>(initialBucketSize, 1);
		mTable.resize(mBucketCount);
	}
	// delete copy and move constructors
	// prevents duplicating and data loses
	UnorderedMap(const UnorderedMap&) = delete;
	UnorderedMap(const UnorderedMap&&) = delete;
	UnorderedMap operator=(const UnorderedMap&) = delete;
	UnorderedMap operator=(const UnorderedMap&&) = delete;

	void Insert(const KeyType& key, const ValueType& value)
	{
		std::size_t index = GetTableIndex(key);
		for(KeyValuePair* pair : mTable[index])
		{
			if(pair->key == key)
			{
				pair->value = value;
				return;
			}
		}

		KeyValuePair* pair = new KeyValuePair();
		pair->key = key;
		pair->value = value;
		mTable[index].push_back(pair);
		++mCount;
		if((double)mCount / (double)mBucketCount > mLoadFactorThreshold)
		{
			Rehash();
		}
	}

	bool Find(const KeyType& key, ValueType& outValue) const
	{
		std::size_t index = GetTableIndex(key);
		for (const KeyValuePair* pair : mTable[index])
		{
			if (pair->key == key)
			{
				outValue = pair->value;
				return true;
			}
		}
		return false;
	}

	bool Has(const KeyType& key) const
	{
		std::size_t index = GetTableIndex(key);
		for (const KeyValuePair* pair : mTable[index])
		{
			if (pair->key == key)
			{
				return true;
			}
		}
		return false;
	}

	bool Remove(const KeyType& key)
	{
		std::size_t index = GetTableIndex(key);
		std::vector<KeyValuePair*>& bucket = mTable[index];
		for (auto it = bucket.begin(); it != bucket.end(); ++it)
		{
			if (it->key == key)
			{
				delete (*it);
				(*it) = nullptr;
				bucket.erase(it);
				--mCount;
				return true;
			}
		}
		return false;
	}

	std::size_t GetCount() const
	{
		return mCount;
	}

	void Clear()
	{
		for (std::vector<KeyValuePair*>& bucket : mTable)
		{
			for(KeyValuePair* pair : bucket)
			{
				delete pair;
				pair = nullptr;
			}
			bucket.clear();
		}
		mTable.clear();
		mCount = 0;
	}

	// data accessors
	ValueType& operator[](const KeyType& key)
	{
		std::size_t index = GetTableIndex(key);
		for (KeyValuePair* pair : mTable[index])
		{
			if (pair->key == key)
			{
				return pair->value;
			}
		}

		KeyValuePair* pair = new KeyValuePair();

		pair->key = key;
		pair->value = mDefault;
		mTable[index].push_back(pair);
		++mCount;
		return pair->value;
	}

	ValueType& operator[](const KeyType& key) const
	{
		std::size_t index = GetTableIndex(key);
		for (KeyValuePair* pair : mTable[index])
		{
			if (pair->key == key)
			{
				return pair->value;
			}
		}
		return mDefault;
	}
	private:
		ValueType mDefault;
		// table is the main vecotr, "Bucket" is a vector of objects using the same index
		std::vector<std::vector<KeyValuePair*>> mTable;
		std::size_t mBucketCount = 0;
		// number of items in the table
		std::size_t mCount = 0;
		// how many items in a bucket before we need to resize the table
		double mLoadFactorThreshold = 1.0;

		// dynamic hash function, gives a hash value from whatever we use as a key
		std::hash<KeyType> mHashFunction;


		std::size_t GetTableIndex(const KeyType & key) const
		{
			return mHashFunction(key) % mBucketCount;
		}

		void Rehash()
		{
			std::size_t newBucketCount = mBucketCount * 2;
			std::vector<std::vector<KeyValuePair*>> newTable(newBucketCount);
			newTable.resize(newBucketCount);
			mBucketCount = newBucketCount;
			for (const std::vector<KeyValuePair*>& bucket : mTable)
			{
				for (const KeyValuePair* pair : bucket)
				{
					std::size_t index = GetTableIndex(pair->key);
					newTable[index].push_back(pair);
				}
				bucket.clear();
			}
			mTable.clear();
			mTable = swab(newTable);
		}
};
