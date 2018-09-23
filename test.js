$("#chatline, #chatbtn").unbind();

$("#chatline").on("keydown", function(ev) {
	if (ev.keyCode==13) {
		socket.emit("chatMsg", {msg:_msg});
		msg = 'abcd';
    }
    return;
    }
