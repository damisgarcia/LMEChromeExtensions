void logmsg(const char* pMsg){
  pp::Var msg(pMsg);
  PostMessage(msg);
}