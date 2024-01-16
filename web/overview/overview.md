# On Web Dev

A web page is consiste of html. The appereance of html is controlled by css. Html can be controled by javascript to perform complex logic and interations.

As to learn the "big three", W3school have elementary tutorials, and MDN has detailed, manual-styled tutorials.

Most developer do not write plain html, css, or javascript. 
Instead developers use frameworks, paired with many libraries, tools, and prewritten code snippets.

Examples of frameworks include react, vue, and nextjs. Other tools include tailwindcss (css framework), shadcn (collection of nice ui components), vite (frontend build tooling), nodejs (javascript runtime environment), npm (nodejs package manager), among others.

React notes are presented in `../react`.

## Frontend Overview

### HTML 

Class name

- `<p className="a b"> </p>: this paragraph belongs to class `a` and class `b`.

*Note*: classname in html can have colon, `:`, but `:` is a special character in CSS.

### CSS

Css selector: 

- `.class`: select class 
- `#id`: select element with id
- `:hover`: a psuedo class. 
- `p:hover`: select paragraph with mouse hover on it.

#### Tailwind

Tailwind uses class names with colons as part of its support for Responsive Design.

For example, tailwind define that `md:` is a class that match device with minimum width 769px. (That is `@media (min-width: 768px) { ... }`).

We have defined a custum class selector `red` as `.red{ color: red}`. 

Thus, in html, a field like `<p className="md:red">red on medium devices</p>` would only be red when the device is wider than 768px.


### Frontend Libraries

#### React:

- Shadcn: form, bottom, and ui components collections.
- chakar ui: collection of react components
- Material ui: collection of react components

### Forms

- Zod: form schema (enforce form rules). Shadcn form uses zod.

## Backend

Backend solutions: appwrite.

## Deployment

Solution: netlify, hostinger.
