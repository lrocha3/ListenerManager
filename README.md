# ListenerManager
Mechanism to notify listeners of events.

The ActivityToListen and Listener classes are the most important files. The logic about the events been notified is made using a queue template that has the listeners associated to a particular activity being listenned.

The actual implementation in the main file uses the ActivityToListen and Listener in a simple way. When I have time I will include the inherence of this classes in other classes to use the listener feature implicitly. This will be the purpose of this project. 
