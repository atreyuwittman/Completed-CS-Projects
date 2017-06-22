#!/bin/sh
echo "#include "./$1.hh"

$1::$1()
{}

$1::~$1()
{}" > $1.cc
echo "#ifndef $1_hh
#define $1_hh

class $1
{
	public:
	$1();
	~$1();

	private:
};
#endif" > $1.hh