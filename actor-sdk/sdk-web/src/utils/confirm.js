/*
 * Copyright (C) 2015-2016 Actor LLC. <https://actor.im>
 */

import React, { Component, PropTypes, createElement } from 'react';
import { render, findDOMNode, unmountComponentAtNode } from 'react-dom';
import { KeyCodes } from '../constants/ActorAppConstants';
import ComposeActionCreators from '../actions/ComposeActionCreators';
import { IntlProvider, FormattedMessage } from 'react-intl';
import { getIntlData } from '../l18n';
import SharedContainer from '../utils/SharedContainer';

class Confirm extends Component {
  static propTypes = {
    message: PropTypes.oneOfType([
      PropTypes.arrayOf(PropTypes.node),
      PropTypes.node
    ]).isRequired,
    description: PropTypes.string,
    abortLabel: PropTypes.string,
    confirmLabel: PropTypes.string
  };

  constructor(props) {
    super(props);

    this.promise = new Promise((resolve, reject) => {
      this.reject = reject;
      this.resolve = resolve;
    });

    const SharedActor = SharedContainer.get();
    this.intlData = getIntlData(SharedActor.forceLocale);
  }

  componentDidMount() {
    ComposeActionCreators.toggleAutoFocus(false);
    findDOMNode(this.refs.confirm).focus();
    document.addEventListener('keydown', this.onKeyDown, false);
  }

  componentWillUnmount() {
    ComposeActionCreators.toggleAutoFocus(true);
    document.removeEventListener('keydown', this.onKeyDown, false);
  }

  render() {
    const { message, description, abortLabel, confirmLabel } = this.props;

    return (
      <IntlProvider {...this.intlData}>
        <div className="modal modal--confirm">
          <header className="modal__header">
            <h4 className="modal__header__title">{message}</h4>
          </header>
          {
            description
              ? <div className="modal__body">{description}</div>
              : null
          }
          <footer className="modal__footer text-right">
            <button className="button" onClick={this.reject}>
              {abortLabel || <FormattedMessage id="button.cancel"/>}
            </button>
            <button className="button button--lightblue" onClick={this.resolve} ref="confirm">
              {confirmLabel ||<FormattedMessage id="button.ok"/>}
            </button>
          </footer>
        </div>
      </IntlProvider>
    );
  }

  onKeyDown = (event) => {
    if (event.keyCode === KeyCodes.ESC) {
      event.preventDefault();
      this.reject();
    }
  };
}

export default function confirm(message, options = {})  {
  let element = document.createElement('div');
  element.className = 'modal-backdrop';
  const wrapper = document.body.appendChild(element);

  const component = render(createElement(Confirm, {message, ...options}), wrapper);

  function cleanup() {
    unmountComponentAtNode(wrapper);
    setImmediate(() => wrapper.remove());
  }

  // Unmount component and remove it from DOM
  component.promise.then(
    () => cleanup(),
    () => cleanup()
  );

  return component.promise;
}
