void LOG(const char*);

static void staticF(){
    LOG("static!");
};

void nonStatic(){
    LOG("not static!");
}

static int x=0;

void INIT() {
    staticF();
    LOG("hello!");
}




