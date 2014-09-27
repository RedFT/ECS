HOW TO BUILD
===

From the terminal, execute either:

    $ make debug 

or:

    $ make release

then in the root project directory, execute:

    $ ./ECS 


DEPENDENCIES
===

    cmake sdl2 sdl2_image glib2 make gcc


ECS
===

Game Engine Based on Entity Component System.

This is one of many attempts at making a game engine in C.

This game engine specifically uses a 'Component based Entity System.'

The App (or game) will be composed of managers (Event Manager, Scene Manager,
RenderManager, etc).

Each Manager will be composed of Entities (Player, Enemy, Camera,
any game object, etc) and Subsystems (Event Subsystem, Movement Subsystem,
Transformation Subsystem, etc).

In order for a subsystem to act upon an entity, it must be registered with
the subsystem. That way, we can insure that the entity has the correct components
for the subsystem to manipulate. Rather than looping through a list of ALL
entities, we can loop through a list of entities with the correct components
(the registered entities).

** all update functions must take a second parameter 'sf' for speed factor. 

So far, this is what the Composition Heirarchy is looks like:


    App:
        Event Manager:
            Keyboard Subsystem,   // Gets the state of the keyboard.
            Mouse    Subsystem,   // Gets the state of the mouse.
            
            Keybaord Uint8[],     // Holds the state of the keyboard.
            Mouse    int[],       // Holds the state of the mouse.
                                  
        Scene Manager:
            Event    Subsystem,   // Gets the state of keyboard and mouse sends
                                  // appropriate events to each Entity depending 
                                  // on which Entity registered for which event.
                                  // Holds a reference to the Event Manager
                                  // to emit keyboard and mouse events.
                                  
            Movement Subsystem,
            Leveling Subsystem,
            ...                   // Probably many more subsystems.
            
            Event    Entities,    // These are just event objects containing 
                                  // different types of information, depending 
                                  // on the event type. Each event is derived from 
                                  // an Event struct.
            
            Game     Entities[]   // Like player, enemies, door, etc.
                                  // All derived from the entity struct.
                                  // All have a dynamic array to hold events
                                  // (like a mailbox) sent from the Event 
                                  // Subsystem.
                                  
        Render Manager:
            Render   Subsystem,   // Gets all objects that need to be rendered from 
                                  // the Scene Manager.
                                  
            Renderer Entity       // With information like Window Size and
                                  // probably references to SDL_Window and
                                  // SDL_Renderer.
