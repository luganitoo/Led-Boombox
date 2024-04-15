
# Music-Reactive LED Boombox

![gif video](https://raw.githubusercontent.com/luganitoo/Led-Boombox/main/demonstration_video1.gif)



[![](https://markdown-videos-api.jorgenkh.no/youtube/6WLHqHHJZ0w)](https://www.youtube.com/watch?v=6WLHqHHJZ0w)


Hey there!

This project means a lot to me because it's the one that really got me hooked on coding. 
You know how it is in the first years of college – the exercises can be pretty dull and demotivating, so coding starts feeling like a real drag.
But what got me excited was this idea I had to create a music-reactive LED display. 
I've always been into music, and I've always found light fascinating, so I thought, why not 'see the song'? 

## Getting Started

When I first started out, I had no clue how to make this happen. All I had was some basic C knowledge. I didn't even know what GIT was, let alone OOP or anything fancy like that, so I had to do a ton of reading and a whole bunch of trial and error.

## Challenges and Victories

The task wasn't easy. I struggled with libraries, getting code from GitHub, and all the eletrical problems. But step by step, I figured things out.

- **First Big Win:** My first achievement was making a single led shine as bright as the song volume level. This was really cool, and it was the first actual nice thing that I had ever coded which I could present to non-tech people without any explanation whatsoever.
- **Next Steps:** Second step was to order a MAX7219, a matrix led display. I had to make a few projects with the display to get familiar with it, like a simple Text Scroller.
- **Deep Dive:** Understanding how to translate different sound frequencies into LED columns took me down a rabbit hole of research. I ended up learning about Fast Fourier Transforms (FFTs) and how to implement them, which was a real challenge but totally worth it.
- **Hardware:** Cool, but I also read that the Arduino isn't capable of handling an FFT fast enough to be able to react in real time. Bummer, but I found a solution: the MSGEQ7. A cheap microchip which filters the sound data for you into 7 different bands.

## Bringing It All Together

Once I had all the pieces, I had to wire everything up. It was a bit of a process, but basically, I hooked up a microphone, the MSGEQ7, and the MAX7219 to the Arduino (I used an Arduino Uno). Then in the code, I grabbed the data from the MSGEQ7 and used it to light up the LED columns!

To make things even cooler, I added a drawing of two speakers at the end of the LED matrix that reacts to bass frequencies.

I was very disorganized at the time, so I don't have the schematics, but I'm sure you can find it all online with the keywords from this text. Maybe I upload it once I have the time to re do this project.

Thank you.

