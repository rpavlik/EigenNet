// This is the main DLL file.

#include "stdafx.h"

#include "EigenWrapper.h"

using namespace EigenWrapper;

MatrixXd::MatrixXd(int x, int y)
	: m_(new Eigen::MatrixXd(x, y))
{
	m_ = Eigen::MatrixXd::Random(x, y);
}

MatrixXd::MatrixXd(Eigen::MatrixXd const & mat)
	: m_(new Eigen::MatrixXd(mat))
{
}
