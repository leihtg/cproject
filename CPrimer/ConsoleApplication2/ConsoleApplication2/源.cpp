#include <iostream>  
#include <cstdlib>
#include <boost/thread/thread.hpp>  

boost::mutex m_guard;

int i=10,j=10;

void hello()  
{  
	while(i-->0){
		m_guard.lock();
		std::cout << "one\t"<<i << std::endl;  
		m_guard.unlock();
		boost::this_thread::sleep(boost::posix_time::millisec(10));
	}
}  
void sec(){
	while(j-->0){
		m_guard.lock();
		std::cout << "two\t\t"<<j << std::endl;  
		m_guard.unlock();
		boost::this_thread::sleep(boost::posix_time::millisec(10));
	}
}
int main()  
{  
	boost::thread thrd(&hello);  
	boost::thread secthrd(&sec);
	thrd.join();  
	secthrd.join();
	system("pause");
}  