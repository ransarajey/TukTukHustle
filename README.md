# TukTukHustle
“Tuk Tuk Hustle” is a simple 2D game developed using Qt version 5.15.1. and Qt’s core, gui,
and multimedia modules. It was tested on both Windows and Mac platforms, and it should
compile on Linux systems as well. <br>
<br>
The basic gameplay is, there is a tuk-tuk hailing on a highway. The user has to switch lanes
of the tuk-tuk using W, A, S, and D keys to avoid collision with the oncoming traffic. The user
can also honk five times using the space key to switch the traffic in front of the tuk-tuk and
move the oncoming traffic to the other lane. Using these interactions, users can hail on the
highway as long as they are avoiding a collision. If the tuk-tuk collided with a vehicle in the
traffic, the game will be over. When the game over, the user will get notified about the score
he gained, and a replay button will be displayed.

# Scope/Functionality
• Display keybindings and instructions on the home page.  <br>
• Give the user a “Start” button to enter the game. <br>
• Display a highway in the background of the game. <br>
• Spawn a tuk-tuk. <br>
• Spawn random vehicles on random lanes of the highway. <br>
• Spawn road lines. <br>
• Move vehicles and road lines towards the tuk-tuk with the time. <br>
• Let the user move the tuk-tuk using W, A, S, and D keys on the keyboard. <br>
• Let the user honk using the space key. <br>
• Generate honk sound when a honk spawned. <br>
• Move the vehicles to the other lane when they heard a honk. <br>
• Delete vehicles, honks, and road lines when they move out of the scene to save the
memory. <br>
• Count and increase the score with the time. <br>
• Decrease the horn count when the user honks. <br>
• If the tuk-tuk collided with a vehicle, display the end screen with the final score and
replay button. <br>

# Known issues and bugs
• Game levels are yet to be developed. <br>
• There are only two vehicle types. <br>
• Has to work on sound design more. <br>
• There is no high score feature. <br>
• If the user clicks on the replay button as soon as it appeared, it will get back to the
same screen for once. <br>
