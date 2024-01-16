# Core of javascript

## Import and Export 

There are four kinds of import in javascript:

1. default import: `import foo from 'foo'`
2. named import: `import { foo } from 'foo'`
3. namespace import: `import * as foo from 'foo'`
4. side effect import: `import 'foo'`

See [MDN](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Statements/import).

Importantly,

- Imported element must be exported.
- import name can be [__short-handed__](#short-hand-import).

### <a name="short-hand-import"></a> Short hand import

During import you can drop `.js` extension. Or entirely the file name if it is `index.js`.

```javascript
import "foo"; // same as import "foo.js"
import "./components"; // same as import "./components/index.js"
```

This feature may not be available in some environment. You may need to configure your bundler.

## A note On Typescript

Typescript is a programming language that is a superset of javascript. Importantly, 1. All valid javascript code are valid typescript code. 2. The could will have the same runtime behaviour.

Typescript, additionally, has a type system. The type system can be understood as a static type checker that looks for possible errors at compile time.
