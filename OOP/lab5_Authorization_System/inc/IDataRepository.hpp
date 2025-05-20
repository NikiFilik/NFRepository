#pragma once

#include "User.hpp"

#include <string>
#include <vector>

namespace nf {
	template <typename T>
	class IDataRepositoryCommonFunctionality {
	public:
		virtual std::vector<T> getAll() = 0;
		virtual T* getById(int id) = 0;
		virtual void add(const T& object) = 0;
		virtual void update(const T& object) = 0;
		virtual void remove(const T& object) = 0;

		virtual ~IDataRepositoryCommonFunctionality() = default;
	};

	template <typename T>
	class IDataRepository: public nf::IDataRepositoryCommonFunctionality<T> {

	};

	template <>
	class IDataRepository<nf::User>: public nf::IDataRepositoryCommonFunctionality<nf::User> {
	public:
		virtual nf::User* getByLogin(std::string login) = 0;
	};
}