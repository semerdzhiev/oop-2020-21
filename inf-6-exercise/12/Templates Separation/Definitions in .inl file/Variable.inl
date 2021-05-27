// в този файл се дефинират функциите от съответния шаблон
// той се включва в Variable.h

template<typename T>
Variable<T>::Variable(const T& initialValue, const std::string& initialName)
	: value(initialValue), name(initialName)
{}
