# React

## Componente

In react, every components must be closed. `<Component />` is valid, but `<Component>` is not.

`<Component />` is equivalent to `<Component></Component>`.

## CSS with react.

To modify `className` attribute of name.

```
export default function Try() {
    const tmp = "nice red great";
    return ( <div className={tmp}> </div>) ;
}
```


