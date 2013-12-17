// This is the main DLL file.

#include "stdafx.h"

#include "EigenWrapper.h"

using namespace EigenWrapper;

MatrixXd::MatrixXd(int x, int y)
	: matrix_(new Eigen::MatrixXd(x, y))
	, m_(*matrix_)
{
	m_ = Eigen::MatrixXd::Random(x, y);
}

MatrixXd::MatrixXd(Eigen::MatrixXd const & mat)
	: matrix_(new Eigen::MatrixXd(mat))
	, m_(*matrix_)
{
}

MatrixXd::~MatrixXd()
{
	this->!MatrixXd();
}

MatrixXd::!MatrixXd()
{
	delete matrix_;
	matrix_ = NULL;
}