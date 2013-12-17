// EigenWrapper.h

#pragma once
#include <Eigen/Dense>

using namespace System;

namespace EigenWrapper {

	public ref class MatrixXd
	{
		// TODO: Add your methods for this class here.
	public:
		MatrixXd(int x, int y);
		~MatrixXd();
		!MatrixXd();
		static MatrixXd^ operator *(MatrixXd^ lhs, MatrixXd^ rhs)
		{
			return gcnew MatrixXd(lhs->m_ * rhs->m_);
		}
	internal:
		Eigen::MatrixXd* matrix_;
		Eigen::MatrixXd & m_;
		// Internal constructor for operator results.
		MatrixXd(Eigen::MatrixXd const & matrix);
	};
}
