# Fnaf-Clone 🍕

This is my original implementation of the popular Five Nights at Freddy's game in C++ using the SDL3 graphics library.

## Game Story 👾
Like the original game, the story follows a protagonist who goes by, "Mike Schmidt," a night security guard working at a seemingly innocent family pizzeria. Tasked with monitoring the establishment from midnight to 6 AM, the player must survive against a cast of animatronic characters that begin to behave unpredictably after hours.

Using a network of security cameras, limited power resources, and quick decision-making, the player must manage threats from multiple directions while conserving energy to make it through each night. The game emphasizes tension, timing, and resource management, staying faithful to the core mechanics that made the original experience so memorable.

This project was built entirely from scratch without the use of a game engine, focusing on low-level control of rendering, input handling, and audio through SDL3. It serves as both a technical exploration of real-time systems and a tribute to the atmosphere and design of the original game.


<br />

# How to run the game 🛠️

```shell
mkdir build
cd build
cmake ..
make && ./fnaf1
```
For a one-liner:
```shell
mkdir build && cd build && cmake .. && make && ./fnaf1
```


<br />


# Demo 🎮

<img width="1600" height="720" alt="2" src="https://github.com/user-attachments/assets/66fb3157-26e8-4a87-b542-66f07e8ff1fc" />
<br/>
<img width="1600" height="720" alt="233" src="https://github.com/user-attachments/assets/29d667e2-ea16-4be6-8127-4110f025043c" />
<br/>
<img width="1600" height="720" alt="303" src="https://github.com/user-attachments/assets/641cf046-3bf0-48d8-9cc8-711a6ab93901" />
<br/>
<img width="1280" height="720" alt="520" src="https://github.com/user-attachments/assets/a82e7dd2-0dca-4ba3-9683-a71db6e03c1b" />





<br /> 

# Project Highlights ⭐

<ul>
<li>Built the entire game from the ground up in C++ with SDL3, without relying on any external game engine—demonstrating full control over rendering, input, and system-level design while maintaining code hygiene.</li>
<li>Implemented a custom game loop with precise timing control to handle animations, input polling, and state updates efficiently.</li>
<li>Designed and developed a modular animatronic AI system, where each character operates independently with unique movement patterns and state transitions.</li>
<li>Engineered a real-time resource management system (power usage, camera systems, doors, lights) that directly impacts gameplay and player survival.</li>
<li>Integrated multi-channel audio handling using SDL_mixer, allowing simultaneous playback of sound effects and ambient audio for immersion.</li>
<li>Created a camera system with dynamic switching, mimicking the original game’s surveillance mechanics while maintaining performance</li>
<li>Debugged and refined edge cases involving timing, AI behavior, and input handling to ensure consistent and predictable gameplay.</li>
<li>Structured the project with scalable architecture, making it easy to extend features such as additional nights, mechanics, or animatronics.</li>
</ul>


# Miscellaneous

....
