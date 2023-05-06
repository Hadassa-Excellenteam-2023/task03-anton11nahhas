struct MyComparator {
	template <typename T>
	T operator()(T a, T b) const {
		return a - b;
	}
};