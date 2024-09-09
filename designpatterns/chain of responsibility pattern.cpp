#include <iostream>  
  
// 抽象处理者  
class Handler {  
public:  
    virtual void setNextHandler(Handler* handler) = 0;  
    virtual void handleRequest(int request) = 0;  
};  
  
// 具体处理者A  
class ConcreteHandlerA : public Handler {  
private:  
    Handler* nextHandler;  
  
public:  
    void setNextHandler(Handler* handler) {  
        nextHandler = handler;  
    }  
  
    void handleRequest(int request) {  
        if (request <= 10) {  
            std::cout << "ConcreteHandlerA处理请求" << request << std::endl;  
        }  
        else if (nextHandler != nullptr) {  
            nextHandler->handleRequest(request);  
        }  
    }  
};  
  
// 具体处理者B  
class ConcreteHandlerB : public Handler {  
private:  
    Handler* nextHandler;  
  
public:  
    void setNextHandler(Handler* handler) {  
        nextHandler = handler;  
    }  
  
    void handleRequest(int request) {  
        if (request > 10 && request <= 20) {  
            std::cout << "ConcreteHandlerB处理请求" << request << std::endl;  
        }  
        else if (nextHandler != nullptr) {  
            nextHandler->handleRequest(request);  
        }  
    }  
};  
  
// 具体处理者C  
class ConcreteHandlerC : public Handler {  
private:  
    Handler* nextHandler;  
  
public:  
    void setNextHandler(Handler* handler) {  
        nextHandler = handler;  
    }  
  
    void handleRequest(int request) {  
        if (request > 20) {  
            std::cout << "ConcreteHandlerC处理请求" << request << std::endl;  
        }  
        else if (nextHandler != nullptr) {  
            nextHandler->handleRequest(request);  
        }  
    }  
};  
  
int main() {  
    // 创建具体处理者对象  
    ConcreteHandlerA handlerA;  
    ConcreteHandlerB handlerB;  
    ConcreteHandlerC handlerC;  
  
    // 设置处理链  
    handlerA.setNextHandler(&handlerB);  
    handlerB.setNextHandler(&handlerC);  
  
    // 发送请求  
    handlerA.handleRequest(5);  // ConcreteHandlerA处理请求5  
    handlerA.handleRequest(15);  // ConcreteHandlerB处理请求15  
    handlerA.handleRequest(25);  // ConcreteHandlerC处理请求25  
  
    return 0;  
}  
