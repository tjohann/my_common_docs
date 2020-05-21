some tmux related stuff
=======================


start new session
-----------------

	tmux new -s basic
	tmux new -s next_session -d   <- do not attach to next_session


commands
--------

	ctrl-a t -> clock


sessions
--------

	ctrl-a d -> detach

	tmux ls

	tmux attach-session -t basic

	tmux kill-session -t basic
