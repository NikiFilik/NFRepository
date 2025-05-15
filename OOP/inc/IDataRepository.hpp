#pragma once

#include "User.hpp"

#include <string>
#include <vector>

namespace nf {
	template <typename T>
	class IDataRepository {
	public:
		virtual std::vector<T> getAll() = 0;
		virtual T* getById(int id) = 0;
		virtual void add(const T& object) = 0;
		virtual void update(const T& object) = 0;
		virtual void remove(const T& object) = 0;

		virtual ~IDataRepository() = default;
	};

	template <>
	class IDataRepository<nf::User> {
	public:
		virtual std::vector<nf::User> getAll() = 0;
		virtual nf::User* getById(int id) = 0;
		virtual void add(const nf::User& object) = 0;
		virtual void update(const nf::User& object) = 0;
		virtual void remove(const nf::User& object) = 0;

		virtual nf::User* getByLogin(std::string login) = 0;

		virtual ~IDataRepository() = default;
	};
}