# The Invisible Percussion Kit
#### Sarah O'Brien - Digital Musical Instrument Design - Spring Quarter 2019 - Prof Stephan Moore

### The Instrument && The User

The Invisible Percussion Kit employs the already-existing visual and tactile mappings associated with drumming and percussion in order to make sounds on "invisible" percussive instruments. The instrument is programmed with 4 percussion sounds and, depending on where and how hard the player "hits" the air with the instrument's sticks, a specific sound will be emitted. The instrument was created to be an instrument played in an ensemble or band as opposed to a solo instrument, but users are encouraged to use the instrument as they see fit.

The Invisible Percussion Kit is an instrument meant both for non-percussionists looking to make music with friends and for aspiring or experienced percussionists who don't have or can't afford a drum kit or a specific set of percussive instruments. Using this instrument, anyone can make a beat with just the two sticks and a computer without having to lug around heavy or noisy percussion equipment.

### Range of Musical Expression

The Invisible Percussion Kit allows a user to obtain his or her expected (as opposed to random) audio results from any given action while not being so rigid as not to allow any true musical expression. So, although the directions of air-hits are pre-programmed in order to provide expected outcomes, the user still has the freedom to change the both sound programmed onto each stick motion (in the code) and the  volume at which each sound is played (depending on how "fast" the user hits the air in that location). 

Allowing for higher volumes on harder hits and lower volumes on softer hits creates space for the user to have fun with the instrument and to be more expressive overall on the the Invisible Percussion Kit. 

### The Technology

#### The Hardware

The Invisible Percussion Kit is built using an Arduino Uno and two ADXL 337 accelerometers. Each accelerometer is mounted inside the top of a cardboard paper towel tube and wire feeds through the bottom of the tube to communicate with the Arduino.

#### The Software

The software for the Invisible Percussion Kit is written in both Arduino and Max. The signal processing is done in Arduino, and using serial communication the Arduino writes information to Max when a drum-hit is detected. In particular, Arduino writes the number associated with the drum hit detected (based on directional information from the accelerometer) and the volume at which to play the audio signal (based on the acceleration of the detected hit). Max then plays the given signal at the given volume. 

The Arduino code employs a moving-average filter and debouncing techniques in order to make use of the instrument easier. The moving-average filter ensures that if a user's wrist twists slightly on a hit the instrument won't play an unexpected sound (one that isn't associated with the direction in which the hit is made). Debouncing ensures that the signal from the acceleration of a stick coming __off__ a hit won't result in the sound being played a second time.

### The Challenges && The Future

The most challenging piece of creating this instrument was incorporating the accelerometer data in a way that made for an accurate instrument. Specifically, because there is no way to anchor the sticks in any one orientation, it was easy for the axes to become misaligned and therefore the expected results of air hits to fail to occur. Using the moving-average filter and debouncing as signal processing techniques helped a lot to overcome these challenges, but there is still much more signal processing that would need to go into the code to make this instrument work as expected all the time. Apart from a software fix, some kind of finger holes or hand strap to anchor the hand so the user doesn't accidentally twist the sticks may be a helpful component to add to this instrument.

Besides improving the action of the instrument and because a piece of the intended musical expression of the Invisible Percussion Kit is the ability to change the sounds programmed, creating a user-friendly GUI in order to upload percussion (or any other) sounds and choose which hits will correspond to each sound would be a useful and exciting next step for this instrument.

I learned a lot creating this instrument and believe that with these changes the Invisible Percussion Kit could be a really exciting instrument for many different people with differing levels of skill to play with!

### Images && Video Demo

#### Image Documentation
![sticks](/images/sticks.jpg)
Shown above are the sticks, which are the two physical pieces of the Invisible Percussion Kit.

![top](/images/top.jpg)
Shown above is the open top of one of the sticks. You can see the mounted accelerometer at the top.

![arduino](/images/arduino.jpg)
Shown above is the wiring of the arduino. Each stick is plugged into the breadboard via protoboard (left stick is plugged into top 6 rows and right stick is plugged in immediately below.

#### Video Demo
{% include youtubePlayer.html id=page.oSiBOY4iwuY %}
