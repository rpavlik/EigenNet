// EigenWrapper.h

#pragma once
#include <Eigen/Dense>

using namespace System;

namespace EigenWrapper {
	template<typename T>
	ref class ValuePointerOwner
	{
	public:
		explicit ValuePointerOwner(T * p)
			: p_(p)
			, ref_(*p)
		{}

		ValuePointerOwner(T const & other)
			: p_(new T(other))
			, ref_(*p)
		{}

		// Warning C++ programmers - this is a non-standard operator= because it returns nothing
		void operator=(T const & other)
		{
			if (&other != p_) {
				ref_ = other;
			}
		}

		!ValuePointerOwner() { delete p_; }
		~ValuePointerOwner() { this->!ValuePointerOwner(); }

		T & get() { assert(p_); return ref_; }
	private:
		T * p_;
		T & ref_;
	};

	public ref class MatrixXd
	{
		// TODO: Add your methods for this class here.
	public:
		// Constructor from size
		MatrixXd(int x, int y);

		static MatrixXd^ operator *(MatrixXd^ lhs, MatrixXd^ rhs)
		{
			return gcnew MatrixXd(lhs->m_.get() * rhs->m_.get());
		}
	internal:
		ValuePointerOwner<Eigen::MatrixXd> m_;
		// Internal constructor for operator results.
		MatrixXd(Eigen::MatrixXd const & matrix);
	};
}
