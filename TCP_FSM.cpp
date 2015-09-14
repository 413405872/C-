/*TCP状态转换图:参考：
http://blog.chinaunix.net/uid-28311809-id-3853883.html
*/

enum status{
	CLOSED,
	LISTEN,
	ESTABLISED,
	SYN_RCVD,
	SYN_SENT,
	FIN_WAIT_1,
	FIN_WAIT_2,
	TIME_WAIT,
	CLOSE_WAIT,
	LAST_ACK
};

//ESTABLISED建立以后可以接受发送数据
int receive(void *buff, size_t len){
	int len = 0;
	/*
	这里是len接收到的数据，处理数据啥的
	*/
	return len;
}

int sent(void *buff, size_t len){
	int len = 0;
	/*
	这里是发送的数据
	*/
	return len;
}

//首先我们要写好各个状态之间的转换函数
//closed这个状态是单独的，刚开始都处于这个状态,它到主机S的SYN_SENT是S自己主动打开的，要发送SYN
status closed(){
	status newStatus;
	//这个就是一个关闭的状态，就是一些清除工作
}

//函数listen_2_syn_rcvd从LISTEN状态到SYN_RCVD状态，这中间是接收到SYN，并且回复ACK和SYN
status listen_2_syn_rcvd(){
	status newStatus;
	//接收来自主机S发来的SYN k,并对其进行k++
	//向主机S发送确认的ACK = k++, 并且发送同步消息SYN=j；
	newStatus = SYN_RCVD;
	status_operator(newStatus);
}

//函数syn_rcvd_2_established从syn_rcvd状态到established，这中间应该接收到主机的ack响应
status syn_rcvd_2_established(){
	status newStatus;
	//主机S发来我刚刚发的SYN j的加1操作，j++;
	newStatus = ESTABLISED;
	status_operator(newStatus);
}

//函数syn_sent_2_established从syn_sent状态到established，这中间是接收到了SYN j和ACK k++并且还要发送ACK为j++
status syn_sent_2_established(){
	status newStatus;
	//处理上面说的j++，发送ACK
	newStatus = ESTABLISED;
	status_operator(newStatus);
}

status established_2_fin_wait_1or_close_wait(){
	status newStatus;
	//建立连接成功了，可以发送数据啥的；
	char *rbuf[1024],*wbuf[1024];
	receive(rbuf,1024);
	/*各种操作*/
	sent(wbuf,1024);
	//数据操作完之后
	if(/*主动关闭连接*/){//主动关闭的它发送了一个FIN，然后进入FIN_WAIT_1
		newStatus = FIN_WAIT_1;
	}
	else //被动关闭的，收到了一个FIN，然后自己回复ACK
		newStatus = CLOSE_WAIT;
	status_operator(newStatus);
}

status fin_wait_1_2_fin_wait_2(){
	status newStatus;
	//主动发送fin的主机收到对方的ACK，此时状态会改变
	newStatus = FIN_WAIT_2;
	status_operator(newStatus);
}

status fin_wait_2_2_time_wait(){
	status newStatus;
	//这个是从FIN_WAIT_2状态又收到对方主机的FIN，自己还会响应一个ACK
	newStatus = TIME_WAIT;
	status_operator(newStatus);
}

status time_wait_2_closed(){
	status newStatus;
	//这个时候要等待2MSL，因为从在2MSL内如果对方没有再发FIN说明对方收到了
	newStatus = CLOSED;
	status_operator(newStatus);
}

status close_wait_2_last_ack(){
	status newStatus;
	//这个时候自己也要关闭了,所以自己要发一个fin
	newStatus = LAST_ACK;
	status_operator(newStatus);
}

status last_ack_2_closed(){
	status newStatus;
	//这个时候它应该收到对方的ack了
	newStatus = CLOSED;
	status_operator(newStatus);
}

//下面是状态选择函数，采用switch
void status_operator(status s){
	switch(s){
		case LISTEN:
			listen_2_syn_rcvd();
			break;
		case ESTABLISED:
			established_2_fin_wait_1or_close_wait();
			break;
		case CLOSED:
			closed();
			break;
		case SYN_RCVD:
			syn_rcvd_2_established();
			break;
		case SYN_SENT:
			syn_sent_2_established();
			break;
		case FIN_WAIT_1:
			fin_wait_1_2_fin_wait_2();
			break;
		case FIN_WAIT_2:
			fin_wait_2_2_time_wait();
			break;
		case TIME_WAIT:
			time_wait_2_closed();
			break;
		case CLOSE_WAIT:
			close_wait_2_last_ack();
			break;
		case LAST_ACK:
			last_ack_2_closed();
			break;
		default:
			break;
	}
}