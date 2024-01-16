# On Css

## Animations

It is possible to set animation and simple interaction with css.

For example: 

```css
.logo {
  height: 6em;
  padding: 1.5em;
  will-change: filter;
  transition: filter 300ms;
}

.logo:hover {
  filter: drop-shadow(0 0 2em #646cffaa); /*change the state when mouse is hovering*/
}
```

The animation is simply a change of state (such as backgound color, filter, etc). The property transition will set the transition animation.
