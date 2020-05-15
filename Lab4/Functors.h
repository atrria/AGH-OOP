#pragma once

namespace Functors
{
	class divisibleBy
	{
	private:
		int i;
	public:
		divisibleBy(int n): i(n){}
		bool operator()(int n)
		{
			return (!(n % i));
		}
	};
	class greaterThan
	{
	private:
		int i;
	public:
		greaterThan(int n): i(n){}
		bool operator()(int n)
		{
			return n>i;
		}
	};
}